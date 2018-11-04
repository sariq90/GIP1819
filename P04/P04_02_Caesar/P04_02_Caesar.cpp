#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text = "";
	int offset = 0;

	cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
	getline(cin, text);
	cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl): ";
	cin >> offset;
	offset %= 26;
	
	for (int i = 0; i < text.length(); i++)
	{
		//Grossbuchstabenbehandlung
		if (text.at(i) >= 'A' && text.at(i) <= 'Z')
		{
			text.at(i) += offset;
			if (text.at(i) > 'Z')
			{
				text.at(i) -= 26;
			}
		}
		//Kleinbuchstabenbehandlung
		else if (text.at(i) >= 'a' && text.at(i) <= 'z')
		{
			text.at(i) += offset;
			if (text.at(i) > 'z')
			{
				text.at(i) -= 26;
			}
		}
		//Restbehandlung (nix verändern)
	}
	
	cout << text << endl;

	system("pause");
	return 0;
}