#pragma once

#include <windows.h>
#include <iostream>
#include <string>

void Systeminfo() {
	std::string comand; // Variabil "comand" în care se stochează comamdele de la utilizatorul
	SYSTEM_POWER_STATUS baterie; // Variabil "baterie" în care se stochează procenrul de baterie
	SetConsoleOutputCP(CP_UTF8); // Setarea limbei română în terminal
	SetConsoleCP(CP_UTF8);       //
	if (GetSystemPowerStatus(&baterie)) {																				 //
		if (baterie.BatteryLifePercent != 225) {																		 //
			std::cout << "Procet de baterie: " << (int)baterie.BatteryLifePercent << "%" << std::endl; // Afișează procentul de baterie
		}																															 //
	}																																 //
}