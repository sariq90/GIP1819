#include <iostream>
using namespace std;

int main()
{
	int min = 1, max = 100;
	char select = 'a';

	cout << "Merken Sie sich eine Zahl zwischen 1 (inklusive) und 100 (exklusive)" << endl;

	//Endlosschleife, bis richtig geraten wurde
	while (select != 'j')
	{
		cout << "Aktueller Ratebereich: " << min << " bis " << max << endl;
		cout << "Ist " << min + (max - min) / 2 << " Ihre Zahl?" << endl <<
			"(j) ja: gleich,\n" << "(k) nein: meine Zahl ist kleiner,\n" << "(g) nein: meine Zahl ist groesser.\n? ";
		cin >> select;
		if (select == 'g')
		{
			//Berechnung neues Minimum
			min = min + (max - min + 1) / 2;
		}
		else if (select == 'k')
		{
			//Berechnung neues Maximum
			max = min + (max - min) / 2;
		}
	}
	system("pause");
	return 0;

}