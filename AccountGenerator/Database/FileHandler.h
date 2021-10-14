#pragma once

#include <string>
#include <fstream>

struct FileData
{
	std::string _path;
	std::string _extension;
	std::string _contents;

	FileData(const char* _path, const std::string& _contents)
		: _path(_path), _contents(_contents)
	{
	}
};

class FileHandler
{
public:
	static FileData ReadFromFile(const char* _path)
	{
		std::ifstream in(_path, std::ios::binary);
		if (in) {
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();
			return { _path, contents };
		}
		throw(errno);
	}

	static void WriteToFile(const char* _path, const char* _contents, const char& _opt = 'a')
	{
		std::ofstream out(_path);
		if (out) {
			if (_opt == 'a') {
				out << _contents << '\n';
			}
			else {
				out.clear();
				out << _contents;
			}
			out.close();
		}
	}

	static void WriteToFile(const char* _path, const std::string& _contents, const char& _opt = 'a')
	{
		std::ofstream out(_path);
		if (out) {
			if (_opt == 'a') {
				out << _contents << '\n';
			}
			else {
				out.clear();
				out << _contents;
			}
			out.close();
		}
	}

	static void ClearFileData(const char* _path)
	{
		std::ofstream out(_path);
		if (out) {
			out.clear();
			out.close();
		}
	}

private:
	FileHandler() = default;
};