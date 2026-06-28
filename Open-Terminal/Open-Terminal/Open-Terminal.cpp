#include "ComandParser.hpp"

using namespace std;

int main() {
	std::string comand; // Variabil "comand" în care se stochează comamdele de la utilizatorul
	fs::path path = fs::current_path(); // Variabil "path" în care se stochează calea în care se află utilizatorul
	do {
		std::cout << "Open-Terminal> ";
		std::cin >> comand;
		path = ComandParser(comand, path);
	} while (comand != "end");
	return 0;
}