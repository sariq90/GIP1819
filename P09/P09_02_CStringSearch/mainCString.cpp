// Datei: main.cpp
#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
using namespace std;
#include "suchen.h"
int main()
{
	if (Catch::Session().run()) {
		system("PAUSE"); return 1;
	}
	// Aufnahme
	const int len = 20;
	int pos = -1;
	char* text_ptr = new char[20];
	char* zkette_ptr = new char[20];
	cout << "Bitte geben Sie den Text ein: ";
	cin.getline(text_ptr, len);
	cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ";
	cin.getline(zkette_ptr, len);
	pos = zeichenkette_suchen(text_ptr, zkette_ptr);
	if (pos == -1)
	{
		cout << "Die Zeichenkette '" << zkette_ptr << "' ist NICHT in dem Text '" << text_ptr << "' enthalten." << endl;
	}
	else
	{
		cout << "Die Zeichenkette '" << zkette_ptr << "' ist in dem Text '" << text_ptr << "' enthalten." << endl;
		cout << "Sie startet ab Zeichen " << pos << " (bei Zaehlung ab 0)." << endl;
	}
	// Saubermachen
	delete text_ptr;
	delete zkette_ptr;
	text_ptr = nullptr;
	zkette_ptr = nullptr;

	system("PAUSE");
	return 0;
}
