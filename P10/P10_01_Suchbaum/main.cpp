#include "binaerer_suchbaum.h"
#include <iostream>

int main()
{
	int eingabe = 0;
	suchbaum::BaumKnoten *anker = nullptr;
	suchbaum::ausgeben(anker);
	while (true)
	{
		std::cout << "Naechster Wert (99 beendet): ? ";
		std::cin >> eingabe;
		if (eingabe == 99)
			break;
		else
			suchbaum::einfuegen(anker, eingabe);
	}

	//suchbaum::einfuegen(anker, 10);
	//suchbaum::einfuegen(anker, 4);
	//suchbaum::einfuegen(anker, 6);
	//suchbaum::einfuegen(anker, 15);
	//suchbaum::einfuegen(anker, 13);
	//suchbaum::einfuegen(anker, 12);
	//suchbaum::einfuegen(anker, 15);
	//suchbaum::einfuegen(anker, 20);
	//suchbaum::einfuegen(anker, 11);
	//suchbaum::einfuegen(anker, 15);
	suchbaum::ausgeben(anker);

	system("pause");
	return 0;
}