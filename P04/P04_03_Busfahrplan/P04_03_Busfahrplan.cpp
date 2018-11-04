#include <iostream>
using namespace std;

int main()
{
	int timeH = -1, timeM = -1, clockM = 0;

	//Eingabe Startuhrzeit
	do
	{
		cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
		cin >> timeH;
	} while (timeH < 0 || timeH >= 24);
	do
	{
		cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
		cin >> timeM;
	} while (timeM < 0 || timeM >= 60);

	cout << "Der erste Bus faehrt also um " << timeH << ":" << timeM << " Uhr.\n";
	
	//Eingabe Taktzeit
	do
	{
		cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
		cin >> clockM;
	} while (clockM <= 0 || clockM >= 180);

	//Mach, solang vor Mitternacht
	while (timeH < 24)
	{
		cout << timeH << ":" << timeM << " ";
		timeM += clockM;
		if (timeM >= 60)
		{
			cout << endl;
			timeH = timeH + timeM/60;
			timeM = timeM%60;
		}
	}

	system("pause");
	return 0;
}