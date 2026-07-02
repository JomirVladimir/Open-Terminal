#pragma once

#include "FunctionFileList.hpp"

namespace fs = std::filesystem;

void DirectoryMaker(fs::path path) {
	SetConsoleOutputCP(CP_UTF8); // Setarea limbei română în terminal
	SetConsoleCP(CP_UTF8);       //
	std::string name_dir;
	std::cout << "Introduceți numele directivei: ";
	std::cin >> name_dir;
	fs::create_directory(name_dir);
	FileList(path);
}