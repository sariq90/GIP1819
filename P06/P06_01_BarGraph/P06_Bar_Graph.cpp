#include <iostream>
#include <string>

void barGraph();

int main()
{
	barGraph();
	
	system("pause");
	return 0;
}

void barGraph()
{
	const int asize = 5;
	int bars[asize] = { 0 };
	int input = 0;

	for (int i = 0; i < asize; i++)
	{ //Arraybefüllung
		do
		{ //Validitätsprüfung
			std::cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			std::cin >> input;
			std::cin.clear();
		} while (input < 1 || input > 9);
		bars[i] = input;
	}
	for (int i = 9; i > 0; i--)
	{ //Zeilenbehandlung
		std::cout << i;
		for (int j = 0; j < asize; j++)
		{ //Spaltenbehandlung
			if (i > bars[j])
			{
				std::cout << ".";
			}
			else if (i < bars[j])
			{
				std::cout << "+";
			}
			else
			{
				std::cout << "*";
			}
		}
		std::cout << std::endl;
	}
	//Kosmetik
	std::cout << " ";
	for (int i = 0; i < asize; i++)
	{
		std::cout << i + 1;
	}
	std::cout << std::endl;
}
