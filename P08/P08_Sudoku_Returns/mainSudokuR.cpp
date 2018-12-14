#include <iostream>
#include <string>
using namespace std;

int main()
{	//Vars
	string eingabe[11] = {};
	int sudoku[9][9] = { 0 };
	int y = 0;
	int check[9] = { 0 };
	bool gueltig = true;
	//Eingabeaufforderung und Abspeichern im String-Array
	cout << "Bitte geben Sie das Sudoku ein: " << endl;
	for (int i = 0; i < 11; i++)
	{
		cin >> eingabe[i];
	}
	//Abspeichern als Integer-Array
	for (int i = 0; i < 11; i++)
	{
		if (i == 3 || i == 7)
		{	//Ignoriere Linien mit Trennzeichen
			continue;
		}
		int x = 0;
		int len = eingabe[i].length();
		for (int j = 0; j < len; j++)
		{	//Falls Char zwischen 1 und 9: Typecast auf Int und ab ins Int-Array "sudoku"
			if (eingabe[i][j] >= '1' && eingabe[i][j] <= '9')
			{
				sudoku[y][x] = int(eingabe[i][j] - '0');
				x++;
			}
		}
		y++;
	}
	//Prüfung auf Richtigkeit
	//Spalten
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{	//Zähle Vorkommen der Ziffern
			check[sudoku[j][i]-1]++;
		}
		for (int k = 0; k < 9; k++)
		{	//Was passiert, wenn Ziffern nicht nur 1x vorkommen?
			if (check[k] > 1)
			{
				cout << "Spalte " << i << ": Zahl " << k+1 << " kommt mehrfach vor." << endl;
				gueltig = false;
			}
			else if (check[k] == 0)
			{
				cout << "Spalte " << i << ": Zahl " << k + 1 << " kommt nicht vor." << endl;
				gueltig = false;
			}
			check[k] = 0;
		}
	}
	//Zeilen
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{	//Zähle Vorkommen der Ziffern
			check[sudoku[i][j] - 1]++;
		}
		for (int k = 0; k < 9; k++)
		{	//Was passiert, wenn Ziffern nicht nur 1x vorkommen?
			if (check[k] > 1)
			{
				cout << "Zeile " << i << ": Zahl " << k + 1 << " kommt mehrfach vor." << endl;
				gueltig = false;
			}
			else if (check[k] == 0)
			{
				cout << "Zeile " << i << ": Zahl " << k + 1 << " kommt nicht vor." << endl;
				gueltig = false;
			}
			check[k] = 0;
		}
	}
	//Blöcke
	for (int b = 0; b < 9; b++)
	{	//Zähle Vorkommen der Ziffern
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				check[sudoku[b / 3 * 3 + i][b % 3 * 3 + j] - 1]++;
			}
		}
		for (int k = 0; k < 9; k++)
		{	//Was passiert, wenn Ziffern nicht nur 1x vorkommen?
			if (check[k] > 1)
			{
				cout << "Block " << b << ": Zahl " << k + 1 << " kommt mehrfach vor." << endl;
				gueltig = false;
			}
			else if (check[k] == 0)
			{
				cout << "Block " << b << ": Zahl " << k + 1 << " kommt nicht vor." << endl;
				gueltig = false;
			}
			check[k] = 0;
		}
	}
	if (gueltig)
	{
		cout << "Das Sudoku ist gueltig." << endl;
	}

	system("pause");
	return 0;
}