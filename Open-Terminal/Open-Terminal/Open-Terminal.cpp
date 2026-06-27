#include "ComandParser.hpp"

using namespace std;

int main() {
	string answer = "fm";
	do {
		answer = ComandParser("mod", answer);
	} while (answer != "end");
	return 0;
}