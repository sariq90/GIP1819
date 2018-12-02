#include <iostream>
#include <string>
using namespace std;

int main()
{	//Vars
	string eingabe[11] = {};
	int sudoku[9][9] = {0};
	int y = 0;
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
	cout << endl << "Das Sudoku lautet: " << endl;
	//Umformatierte Ausgabe
	for (int i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{	//Horizontale Trennzeichen
			cout << "=======//=======//=======" << endl;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6)
			{	//Vertikale Trennzeichen
				cout << ";//";
			}
			cout << ";" << sudoku[i][j];
			if (j == 8)
			{	//endl am Ende
				cout << endl;
			}
		}
	}

	system("pause");
	return 0;
}