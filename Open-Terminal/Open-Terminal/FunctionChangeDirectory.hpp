#pragma once

#include "FunctionFileList.hpp"


namespace fs = std::filesystem; // Setarea noul numele de spațiul

fs::path ChangeDirectoryKids(fs::path path_kids, fs::path path_parent) {
	SetConsoleOutputCP(CP_UTF8);	// Setarea limbei română în terminal
	SetConsoleCP(CP_UTF8);        //
	for (fs::directory_entry dir_file : fs::directory_iterator(path_parent)) {
		if (dir_file.is_directory()) {
			fs::path dir = dir_file.path();
			if (path_kids == dir.stem()) {
				return dir;
			}
		}
	}
	std::cout << "Directivă nu există\n";
	return path_parent;
}

fs::path ChangeDirectoryParent(fs::path path) {
	path = path.parent_path();
	return path;
}

fs::path ChangeDirectory(fs::path path) {
	SetConsoleOutputCP(CP_UTF8); // Setarea limbei română în terminal
	SetConsoleCP(CP_UTF8);       //
	fs::path argument;
	while (true) {
		FileList(path);
		std::cout << "Introduceți denumirea dirctivei: ";
		std::cin >> argument;
		if (argument == "#") {
			break;
		}
		if (argument == "..") {
			path = ChangeDirectoryParent(path);
		}
		else {
			path = ChangeDirectoryKids(argument, path);
		}
	}
	return path;
}

