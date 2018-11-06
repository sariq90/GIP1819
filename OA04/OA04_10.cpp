#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text = "";
	string text2 = "";


	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, text);

	for (int i = 0; i < text.length(); i++)
	{
		char c = text.at(i);
		if (c >= 'a' && c <= 'z')
		{
			text2 += c;
			text2 += c;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			text2 += c;
			text2 += c;
			text2 += c;
		}
		else if (c >= '0' && c <= '9')
		{
			text2 += '.';
		}
		else if (c == '?' || c == '!')
		{

		}
		else if (c == ' ')
		{
			text2 += '_';
		}
		else
		{
			text2 += c;
		}
	}

	cout << "Der Text nach der Umwandlung: " << text2 << endl;

	system("PAUSE");
	return 0;
}