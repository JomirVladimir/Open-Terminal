#pragma once

#include "FunctionFileList.hpp"

void FileMaker(std::filesystem::path path) {
	SetConsoleOutputCP(CP_UTF8); // Setarea limbei română în terminal
	SetConsoleCP(CP_UTF8);       //
	std::string name_file;
	std::string extension_file;
	std::cout << "Introduceți numele fișierul: ";
	std::cin >> name_file;
	std::cout << "Introduceți extensia fișierul: ";
	std::cin >> extension_file;
	std::fstream new_file;
	new_file.open(name_file + "." + extension_file, std::ios::out);
	new_file.close();
	FileList(path);
}