#include <iostream>
#include <string>
using namespace std;

void O04_11();
void O04_12();

int main()
{
	//O04_11();
	O04_12();
	system("pause");
	return 0;
}

void O04_11()
{
	int width = 2;
	int height = 2;
	cout << "Bitte geben Sie die Breite des Rechtecks ein: ? ";
	cin >> width;
	cout << "Bitte geben Sie die Hoehe des Rechtecks ein: ? ";
	cin >> height;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				cout << '*';
			}
			else
			{
				cout << '+';
			}
		}
		cout << endl;
	}
}

void O04_12()
{
	int width = 2;
	int height = 2;
	cout << "Bitte geben Sie die Breite des Parallelogramms ein: ? ";
	cin >> width;
	cout << "Bitte geben Sie die Hoehe des Parallelogramms ein: ? ";
	cin >> height;

	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < i; k++)
		{
			cout << '.';
		}
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				cout << '*';
			}
			else
			{
				cout << '+';
			}
		}
		cout << endl;
	}
	cout << endl;
}