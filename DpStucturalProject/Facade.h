#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;

class TextEditor
{
public:
	void CreateCode(std::string& fileName)
	{
		if(fileName == "")
			fileName = "noname.cpp";
		std::fstream file(fileName, std::ios::out);
		std::cout << "file with code create\n";
	}

	void SaveAsCode(std::string& fileName)
	{
		if (fileName == "")
			fileName = "noname.cpp";
		std::fstream file(fileName, std::ios::out);
		std::cout << "file with code save\n";
	}
};

class Compiller
{
public:
	std::string Compile(std::string& fileName)
	{
		if (fileName == "")
		{
			std::cout << "file not found\n";
			return "";
		}
		int index = fileName.find('.');
		std::string fileNameOnly = fileName.substr(0, index);
		std::fstream file(fileNameOnly + ".exe", std::ios::out);
		std::cout << "cpp file compile\n";

		return fileNameOnly + ".exe";
	}
};

class Debugger
{
	std::string fileExe;
public:
	std::string& FileExe() { return fileExe; }

	std::string Debug(std::string fileExe)
	{
		int index = fileExe.find('.');
		std::string fileNameOnly = fileExe.substr(0, index);
		fs::remove(fs::path(fileNameOnly + ".cpp"));
		std::fstream file("new_" + fileNameOnly + ".cpp", std::ios::out);

		return "new_" + fileNameOnly + ".cpp";
	}
};

class RunTime
{
public:
	void Execute(std::string app)
	{
		if(fs::exists(fs::path(app)))
			std::cout << "app is run\n";
		else
			std::cout << "app not found\n";
	}
};


class VisualStudioFacade
{
	TextEditor* editor;
	Compiller* compiller;
	Debugger* debugger;
	RunTime* runTime;

	std::string fileName;
	std::string fileExe;

public:
	VisualStudioFacade(TextEditor* editor,
						Compiller* compiller,
						Debugger* debugger,
						RunTime* runTime)
		: editor{ editor },
		compiller{ compiller },
		debugger{ debugger },
		runTime{ runTime } {};

	void Start()
	{
		fileName = "prog.cpp";

		editor->CreateCode(fileName);
		fileExe = compiller->Compile(fileName);
		fileName = debugger->Debug(fileExe);
		fileExe = compiller->Compile(fileName);

		runTime->Execute(fileExe);
	}
};
