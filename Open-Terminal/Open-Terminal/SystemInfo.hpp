#pragma once

#include <windows.h>
#include <iostream>
#include <string>

std::string systeminfo() {
	std::string comand;
	SYSTEM_POWER_STATUS baterie;
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	while (comand != "exit") {
		if (GetSystemPowerStatus(&baterie)) {																				 //
			if (baterie.BatteryLifePercent != 225) {																		 //
				std::cout << "Procet de baterie: " << (int)baterie.BatteryLifePercent << "%" << std::endl; // Afișează procentul de baterie
			}																															 //
		}																																 //
		std::cout << "Terminal\\SI-> ";
		std::cin >> comand; // Citorea comandelor de la utilizatorul
		if (comand == "fm") {
			return "fm";
		}
	}
	return "end";
}