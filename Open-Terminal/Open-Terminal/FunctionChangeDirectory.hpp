#pragma once

#include "FunctionFileList.hpp"


namespace fs = std::filesystem; // Setarea noul numele de spațiul

fs::path ChangeDirectoryKids(fs::path path_kids, fs::path path_parent) {
	SetConsoleOutputCP(CP_UTF8);	// Setarea limbei română în terminal
	SetConsoleCP(CP_UTF8);        //
	for (fs::path dir : fs::directory_iterator(path_parent)) {
		if (path_kids == dir.stem()) {
			FileList(dir);
			return dir;
		}
	}
	std::cout << "Directivă nu există";
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
	std::cout << "Introduceți denumirea dirctivei: ";
	std::cin >> argument;
	if (argument == "..") {
		path = ChangeDirectoryParent(path);
		FileList(path);
		return path;
	}
	else {
		return ChangeDirectoryKids(argument, path);
	}
	return path;
}

