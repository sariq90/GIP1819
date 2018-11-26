#include <iostream>
#include <string>
#include "wortspiegel.h"

using namespace std;

int main()
{
	string text = "";
	cout << "Bitte geben Sie den Text ein: ? ";
	getline(cin, text);

	wortwahl(text);

	system("pause");
	return 0;
}