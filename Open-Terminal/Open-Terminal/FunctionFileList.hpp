#pragma once

#include <iostream> // Biblioteca iostream
#include <filesystem> // Biblioteca cu funcții pentru lucru cu sistemă de fișiere (cu directive)
#include <fstream> // Biblioteca cu funcții pentru lucru cu fișiere
#include <iomanip> // Biblioteca cu funcții pentru lucru cu afișarea textelor în terminal
#include <windows.h> // Biblioteca cu funcții pentru lucru cu windows
#include "ColorText.hpp" // Propria mea biblioteca cu funcția color
 // Propria mea biblioteca cu funcția ComandParser

namespace fs = std::filesystem; // Setarea noul numele de spațiul

void FileList(fs::path path) { // Funcția care lucrează cu sistemul de fișiere
		SetConsoleOutputCP(CP_UTF8); // Setarea limbei română în terminal
		SetConsoleCP(CP_UTF8);       //
		color("33"); // Setarea culoare textului la galben
		std::cout << "Calea curentă: " << path << "\n";
		color("32"); // Setarea culoare textului la verde
		std::cout << std::left << std::setw(31) << "Denumire fișierului";
		color("36"); // Setarea culoare textului la cyan
		std::cout << std::left << std::setw(31) << "Extensia fișierului";
		color("35"); // Setarea culoare textului la violet
		std::cout << "Mărimea fișierului" << "\n";
		for (fs::path file : fs::directory_iterator(path)) { //For-ul care parcurge prin directiva din variabilă "path"
			color("32"); // Setarea culoare textului la verde
			std::cout << std::left << std::setw(30) << file.stem(); // Afișează denumirea fișierului fără extensi sau denumirea directivei 
			color("36"); // Setarea culoare textului la cyan
			std::cout << std::setw(30) << file.extension(); // Afișează extensi al fișierului
			color("35"); // Setarea culoare textului la violet
			std::cout << fs::file_size(file) << "\n"; // Afișează mărimea fișierului în byte
		}
		color("0");
}