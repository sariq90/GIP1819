#include <iostream>
#include <string>
using namespace std;
//_01
void spalte_ab_erstem(char zeichen,
	string eingabe,
	string& erster_teil,
	string& zweiter_teil);
void O06_01();
//_02
int addition_rekursiv(int i, int k);
int subtraktion_rekursiv(int i, int k);
void O06_02();
//_03
const char empty_pixel = '.';
const char filled_pixel = '#';
const int canvas_size = 40;
void init_canvas(char canvas[][canvas_size])
{
	for (int x = 0; x < canvas_size; x++)
		for (int y = 0; y < canvas_size; y++)
			canvas[x][y] = empty_pixel;
}
void print_canvas(char canvas[][canvas_size])
{
	for (int y = 0; y < canvas_size; y++) {
		for (int x = 0; x < canvas_size; x++) {
			cout << canvas[x][y];
		}
		cout << endl;
	}
	cout << endl;
}
void O06_03();

int main()
{
	//O06_01();
	//O06_02();
	//O06_03();

	system("pause");
	return 0;
}
//_01
void spalte_ab_erstem(char zeichen,
	string eingabe,
	string& erster_teil,
	string& zweiter_teil)
{
	int pos = -1;
	const unsigned int len = eingabe.length();
	for (int i = 0; i < len; i++)
	{
		if (eingabe.at(i) == zeichen)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
	{
		erster_teil = eingabe;
		return;
	}
	else
	{
		for (int i = 0; i < pos; i++)
		{
			erster_teil += eingabe.at(i);
		}
		for (int i = pos + 1; i < len; i++)
		{
			zweiter_teil += eingabe.at(i);
		}
	}
	return;
}
void O06_01()
{
	string text = "";
	string text1 = "";
	string text2 = "";
	char c = 'a';
	cout << "Bitte geben Sie die einzeilige Zeichenkette ein: ? ";
	getline(cin, text);
	cout << "Bitte geben Sie das Zeichen ein: ? ";
	cin >> c;
	cin.clear();
	cin.ignore(1000, '\n');
	spalte_ab_erstem(c, text, text1, text2);
	cout << "Der erste Teil der Zeichenkette lautet: " << text1 << endl;
	cout << "Der zweite Teil der Zeichenkette lautet: " << text2 << endl;
	return;
}
//_02
int addition_rekursiv(int i, int k)
{
	if (k == 0)
	{
		return i;
	}
	else
	{
		i++;
		k--;
		addition_rekursiv(i, k);
	}
}
int subtraktion_rekursiv(int i, int k)
{
	if (k == 0)
	{
		return i;
	}
	else
	{
		i--;
		k--;
		subtraktion_rekursiv(i, k);
	}
}
void O06_02()
{
	int i = 0, k = 0;
	cout << "Bitte geben Sie die erste Zahl ein: ? ";
	cin >> i;
	cout << "Bitte geben Sie die zweite Zahl ein: ? ";
	cin >> k;
	cout << i << " + " << k << " = "
		<< addition_rekursiv(i, k) << endl;
	cout << i << " - " << k << " = "
		<< subtraktion_rekursiv(i, k) << endl;
}
//_03
void linie(int x1, int y1, int x2, int y2, char canvas[][canvas_size])
{
	if (x1 - x2 <= 1 && x1 - x2 >= -1 && y1 - y2 <= 1 && y1 - y2 >= -1)
	{
		canvas[x1][y1] = '#';
		canvas[x2][y2] = '#';
	}
	else
	{
		int x_mitte = (x1 + x2) / 2;
		int y_mitte = (y1 + y2) / 2;

		linie(x1, y1, x_mitte, y_mitte, canvas);
		linie(x_mitte, y_mitte, x2, y2, canvas);
	}
}
void O06_03()
{
	char canvas[canvas_size][canvas_size];
	init_canvas(canvas);
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	do {
		cout << "Bitte geben Sie den ersten Punkt ein: ? ";
		cin >> x1 >> y1;
	} while (x1 < 0 || x1 >= canvas_size || y1 < 0 || y1 >= canvas_size);
	do {
		cout << "Bitte geben Sie den zweiten Punkt ein: ? ";
		cin >> x2 >> y2;
	} while (x2 < 0 || x2 >= canvas_size || y2 < 0 || y2 >= canvas_size);
	linie(x1, y1, x2, y2, canvas);
	print_canvas(canvas);
}
