#pragma once
#include "Example.h"
#include "Database/Database.h"
#include "Utility/Tuple.h"


class CMD
{
public:
	CMD(int argc, char** argv)
	{
		auto db = AccountDatabase::SimpleDatabase<User>();
		db.ImportPath(PATH);
		LinkCommands(db);

		while (true)
		{
			PROMPT("<management> ");

			std::string input;
			std::getline(std::cin, input);
			if (!CheckInput(input, db)) {
				PROMPT("Unknown command: \'");
				PROMPT(input);
				LOG("\'");
			}
			LOG("");
		}
	}

private:
	template<typename _Model>
	void LinkCommands(AccountDatabase::SimpleDatabase<_Model>& database)
	{
		auto cmds = database.GetCMDs();
		for (auto& cmd : cmds) {
			m_Cmds.Add(cmd);
		}
	}

	void DisplayCmds()
	{
		for (auto& cmd : m_Cmds)
			LOG(cmd);
	}

	template<typename _Model>
	bool CheckInput(const std::string& _input, AccountDatabase::SimpleDatabase<_Model>& _database)
	{
		if (_input == "help") {
			DisplayCmds();
			return true;
		}
		else if (_input == "exit") {
			exit(0);
		}
		else if (_database.ValidateCMD(_input)) {
			return true;
		}
		else
			return false;
	}

private:
	mtk::List<std::string_view> m_Cmds = {
		"help",
		"exit",
	};
};