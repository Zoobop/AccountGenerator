#pragma once
#include "Model.h"
#include "FileHandler.h"

#include "Structures/List.h"
#include "Structures/Map.h"
#include "DebugUtils/Timer.h"
#include "DebugUtils/Log.h"
#include "Utility/StringUtils.h"


#define PATH					"C:\\Users\\Brandon\\OneDrive\\Desktop\\Code\\C++\\AccountGenerator\\AccountGenerator\\Output\\database.txt"
#define DEFAULT_MEMBER_COUNT	10

namespace AccountDatabase {

	template<typename _ModelType = Model>
	class SimpleDatabase
	{
	public:
		SimpleDatabase()
		{
		}

		bool Add(const _ModelType& _modelObj)
		{
			return m_Registry.Insert(m_EntryCount++, _modelObj);
		}

		bool Add(_ModelType&& _modelObj)
		{
			return m_Registry.Insert(m_EntryCount++, std::move(_modelObj));
		}

		void Commit() const
		{
			Export();

			if (m_EntryCount < 1) {
				LOG("No objects in registry!");
			}
			else {
				std::cout << "Commited objects to registry: " << m_EntryCount << " Entries\n";
			}
		}

		void ClearDatabase()
		{
			m_Registry.Clear();
			m_EntryCount = 0;
			FileHandler::ClearFileData(PATH);
			LOG("Database cleared!");
		}

		bool ObjectExists(const _ModelType& _modelObj)
		{
			for (ID i = 0; i < m_EntryCount; i++) {
				if (m_Registry.At(i) == _modelObj)
					return true;
			}
			return false;
		}

		void PrintRegistry() const
		{
			if (m_EntryCount < 1) {
				LOG("No entries in the registry!");
				return;
			}
			else {
				for (ID i = 0; i < m_EntryCount; i++) {
					auto user = m_Registry.At(i);
					LOG(user);
				}
			}
		}

		const ID& RegistryCount() const { return m_EntryCount; }

		void ImportPath(const std::string& _path)
		{
			m_OutputPath = _path;
			Import();
		}

		virtual bool ValidateCMD(const std::string& _cmd)
		{
			if (_cmd == "registry") {
				PrintRegistry();
				return true;
			}
			else if (_cmd == "count") {
				PROMPT("Number of users: ");
				LOG(m_EntryCount);
				return true;
			}
			else if (_cmd == "add") {
				return CreateUser();
			}
			else if (_cmd == "remove") {
				return RemoveUser(_cmd);
			}
			else if (_cmd == "commit") {
				Commit();
				return true;
			}
			else if (std::string_view(_cmd.c_str(), 6) == "export") {
				return ToFile(_cmd);
			}
			else
				return false;
		}

		virtual mtk::List<std::string_view> GetCMDs() const
		{
			return {
				"registry",
				"count",
				"add",
				"remove",
				"commit",
				"export"
			};
		}

	private:
		bool CreateUser()
		{
			while (true)
			{
				PROMPT("Enter Email: ");
				std::string email;
				std::getline(std::cin, email);
				if (email.size() < 1) {
					LOG("Invalid Email!\n");
					continue;
				}

				PROMPT("Enter Username: ");
				std::string username;
				std::getline(std::cin, username);
				if (username.size() < 1) {
					LOG("Invalid Username!\n");
					continue;
				}

				PROMPT("Enter Password: ");
				std::string password_begin;
				std::getline(std::cin, password_begin);
				if (password_begin.size() < 5) {
					LOG("Invalid Password!\n");
					continue;
				}

				PROMPT("Confirm Password: ");
				std::string password_end;
				std::getline(std::cin, password_end);
				if (password_begin != password_end) {
					LOG("Invalid Password!\n");
					continue;
				}

				_ModelType newUser(m_EntryCount, email, username, password_end);
				if (ObjectExists(newUser)) {
					LOG("User Already Exists!\n");
					continue;
				}

				Add(newUser);
				LOG("Account Successfully Created!\n");
				return true;
			}
		}

		bool RemoveUser(const std::string& _input)
		{
			auto _params = mtk::Split(_input, ' ');

			auto data = _params[1];
			for (ID i = 0; i < m_EntryCount; i++) {
				auto obj = m_Registry.At(i);
				if (obj.GetEmail() == data) {
					m_Registry.Erase(i);
					return true;
				}
			}
			return false;
		}

		void Import()
		{
			std::ifstream in(m_OutputPath.c_str());
			if (in) {
				std::string entryData;
				while (std::getline(in, entryData)) {
					auto objectData = mtk::Split(entryData);
					_ModelType dataObj;
					dataObj.FromString(m_EntryCount, objectData);
					Add(std::move(dataObj));
				}
			}
		}

		void Export() const
		{
			std::ofstream out(m_OutputPath, std::ios::out);
			if (out) {
				for (ID i = 0; i < m_EntryCount; i++) {
					out << m_Registry.At(i).ToString() << '\n';
				}
				out.close();
			}
		}

		bool ToFile(const std::string& _cmd) const
		{
			auto path = mtk::Split(_cmd)[1];

			std::ofstream out(path.data(), std::ios::out);
			if (out) {
				for (ID i = 0; i < m_EntryCount; i++) {
					out << m_Registry.At(i).ToString() << '\n';
				}
				out.close();
				LOG("Export successful!");
				return true;
			}
			LOG("Export failed: No such file found!");
			return false;
		}

	private:
		ID m_EntryCount = 0;
		mtk::Map<ID, _ModelType> m_Registry;
		std::string m_OutputPath;
	};
}