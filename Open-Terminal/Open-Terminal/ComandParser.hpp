#pragma once

#include <string> // Biblioteca cu string
#include <vector> // Biblioteca cu vector
#include <map> // Biblioteca cu map (dicționare)
#include "SystemInfo.hpp" // Propria mea biblioteca cu funcția SystemInfo
#include "FunctionFileList.hpp" // Propria mea biblioteca cu funcția FileManager
#include "ord.hpp" // Propria mea biblioteca cu funcția ord
#include "FunctionChangeDirectory.hpp"

class Comand_list { // Clasa în care se află toate comantele cu id-urile lor
public:
	std::map <std::string, int> ComandList; // Map în care se află toate denumirele de moduri cu id-urile lor
	Comand_list(std::vector <std::string> ListComand) { // Constructor care setează comandele al map-purilor din vectori, care sunt parametri
		for (std::string comand : ListComand) { // For-ul care parcurge prin vector cu comandele
			ComandList[comand] = ord(comand);		 // Se setează comandele cu id-ul lor
		}
	}
};

std::filesystem::path ComandParser(std::string call, std::filesystem::path path) { //Funcția care parsează comandele de la utilizatorul și returnează răpunsul de la alte funcții
	Comand_list list({ "info","ls","cd" }); // Crează obiectul "list" cu clasa "Comand_list"
	std::string answer; // Variabil "answer" în care se stochează răspunsul de la funcții
	switch (list.ComandList[call]) { //Switch-ul principal, care indentifică comandele al cărui mod să parseze, conform id-ul
		case 428: { Systeminfo(); break; }
		case 223: { FileList(path); break; }
		case 199: { return ChangeDirectory(path); }
		default: std::cout << "No found comand" << std::endl; break;
	}
	return path;
}

