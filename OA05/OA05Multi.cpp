#include <iostream>
#include <string>
using namespace std;

void O05_01();
void O05_02();
void O05_03();
void O05_04();
void O05_05();
void O05_06();
void O05_07();
int powerFunc(int, int); //simple power function for use in O05_07.
void O05_08();
string ersetze(string, char, string); //support function for O05_08.
void O05_09();
string trimme(string); //support function for O05_09.

int main()
{
	//O05_01();
	//O05_02();
	//O05_03();
	//O05_04();
	//O05_05();
	//O05_06();
	//O05_07();
	//O05_08();
	O05_09();

	system("pause");
	return 0;
}

void O05_01()
{
	int arr[9] = {};
	for (int i = 0; i < 9; i++)
	{
		int input = 0;
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> input;
		} while (input < 1 || input > 6);
		arr[i] = input;
	}
	for (int i = 0; i < 9; i++)
	{
		cout << "Die " << i + 1 << ". eingegebene Zahl lautete: " << arr[i] << endl;
	}
}

void O05_02()
{
	int arr[6] = {};
	int search = 0;
	bool found = false;
	for (int i = 0; i < 6; i++)
	{
		int input = 0;
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> input;
		} while (input < 1 || input > 6);
		arr[i] = input;
	}
	cout << "Bitte geben Sie die Suchzahl ein: ? ";
	cin >> search;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] == search)
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		cout << "Die Suchzahl kam unter den Eingaben vor." << endl;
	}
	else
	{
		cout << "Die Suchzahl kam NICHT unter den Eingaben vor." << endl;
	}
}

void O05_03()
{
	int arr[4] = {};
	int compareWith = 0;
	int counterHit = 0;
	int counterMiss = 0;

	for (int i = 0; i < 4; i++)
	{
		cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
		cin >> arr[i];
	}
	cout << "Bitte geben Sie die Vergleichszahl ein: ? ";
	cin >> compareWith;
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] == compareWith)
		{
			counterHit++;
		}
		else
		{
			counterMiss++;
		}
	}
	cout << counterHit << " Eingabezahlen waren gleich der Vergleichszahl." << endl;
	cout << counterMiss << " Eingabezahlen waren ungleich der Vergleichszahl." << endl;
}

void O05_04()
{
	int values[9] = {};
	int frequency[6] = {};

	for (int i = 0; i < 9; i++)
	{
		int input = 0;
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> input;
		} while (input < 1 || input > 6);
		values[i] = input;
		frequency[input - 1]++;
	}
	for (int i = 0; i < 9; i++)
	{
		cout << "Die " << i + 1 << ". eingegebene Zahl lautete: " << values[i] << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << "Die Zahl " << i + 1 << " wurde " << frequency[i] << " mal eingegeben." << endl;
	}
}

void O05_05()
{
	int values[9] = {};
	bool present[6] = { false };
	int countDifferent = 0;

	for (int i = 0; i < 9; i++)
	{
		int input = 0;
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> input;
		} while (input < 1 || input > 6);
		values[i] = input;
		present[input - 1] = true;
	}
	for (int i = 0; i < 6; i++)
	{
		if (present[i])
		{
			countDifferent++;
		}
	}
	cout << "In der Eingabe kamen " << countDifferent << " unterschiedliche Zahlen vor." << endl;
}

void O05_06()
{
	int arr[5] = {};
	int min = 0;
	int max = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Die " << i + 1 << ". eingegebene Zahl lautete: " << arr[i] << endl;
	}
	min = arr[0];
	max = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	cout << "Die kleinste eingegebene Zahl lautete: " << min << endl;
	cout << "Die groesste eingegebene Zahl lautete: " << max << endl;
}

void O05_07()
{
	string input = "";

	cout << "Bitte die Zahl oder das Wort 'ende' eingeben: ? ";
	cin >> input;

	if (input == "ende")
	{
		cout << "Das Programm beendet sich jetzt." << endl;
		return;
	}
	else
	{
		int length = input.length();
		int acc = 0;
		for (int i = 0; i < length; i++)
		{
			acc += int(input[length - 1 - i] - '0') * powerFunc(10, i);
		}
		acc *= 2;
		cout << "Der doppelte Wert betraegt: " << acc << endl;
	}

}

int powerFunc(int base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		int power = base;
		for (int i = 1; i < exponent; i++)
		{
			power = power*base;
		}
		return power;
	}
}

void O05_08()
{
	string s1 = "", s2 = "";
	char c;
	cout << "Bitte geben Sie die Textzeile ein: ? ";
	getline(cin, s1);
	cout << "Bitte geben Sie das zu ersetzende Zeichen ein: ? ";
	cin >> c;
	cin.ignore();
	cout << "Bitte geben Sie den einzusetzenden Text ein: ? ";
	getline(cin, s2);
	cout << "Ergebnis: " << ersetze(s1, c, s2) << endl;
}

string ersetze(string zeile, char zu_ersetzendes_zeichen, string ersatztext)
{
	string output = "";
	int length = zeile.length();
	for (int i = 0; i < length; i++)
	{
		if (zeile[i] == zu_ersetzendes_zeichen)
		{
			output += ersatztext;
		}
		else
		{
			output += zeile[i];
		}
	}
	return output;
}

void O05_09()
{
	string s = "";
	cout << "Bitte geben Sie die Textzeile ein: ? ";
	getline(cin, s);
	cout << "Vorher: " << s << endl;
	cout << "Nachher: " << trimme(s) << endl;
}

string trimme(string s)
{
	int length = s.length();
	int clampL = 0;
	int clampR = 0;
	string output = "";

	for (int i = 0; i < length; i++)
	{
		if (s[i] != '+')
		{
			clampR = i + 1;
		}
		if (s[length - 1 - i] != '+')
		{
			clampL = length - 1 - i;
		}
	}
	for (int i = clampL; i < clampR; i++)
	{
		output += s[i];
	}
	return output;
}