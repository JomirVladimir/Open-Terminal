#pragma once

#include "FunctionFileList.hpp"

namespace fs = std::filesystem;

void Delet(fs::path path) {
	SetConsoleOutputCP(CP_UTF8); // Setarea limbei română în terminal
	SetConsoleCP(CP_UTF8);       //
	fs::path name;
	bool flag = false;
	FileList(path);
	std::cout << "Introduceți numele fișierului/directivei: ";
	std::cin >> name;
	for (fs::path file_dir : fs::directory_iterator(path)){
		if (name == file_dir.filename()) {
			fs::remove_all(file_dir);
			FileList(path);
			flag = true;
		}
	}
	if (not(flag)) {
		std::cout << "Nu există " << name << "\n";
	}
}