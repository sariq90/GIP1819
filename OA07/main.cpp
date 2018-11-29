#include <iostream>
#include <string>
using namespace std;

void O07_01();
void O07_02();
void O07_03();

int main()
{
	//O07_01();
	//O07_02();
	O07_03();

	system("pause");
	return 0;
}

void O07_01()
{
	const unsigned int text_n = 4;
	string input = "";
	string texts[text_n];
	unsigned int text_len[text_n] = {};
	unsigned int longest = 0;
	//Pre-fill texts with ""
	for (int i = 0; i < text_n; i++)
	{
		texts[i] = "";
	}
	//Transfer input texts and their lengths to arrays, determine longest string
	for (int i = 0; i < text_n; i++)
	{
		cout << "Textzeile = ? ";
		getline(cin, input);
		if (input == "")
		{
			break;
		}
		else
		{
			texts[i] = input;
			text_len[i] = input.length();
			if (text_len[i] > longest)
			{
				longest = text_len[i];
			}
		}
	}
	//Align right to longest string
	for (int i = 0; i < text_n; i++)
	{
		if (texts[i] == "")
		{
			break;
		}
		else
		{
			for (int k = 0; k < longest - text_len[i]; k++)
			{
				cout << '#';
			}
			cout << texts[i] << endl;
		}
	}
}

void O07_02()
{
	char w = 'w', i = 'i', l = 'l';
	char* ptr = nullptr;

	ptr = &w;
	cout << *ptr;
	ptr = &i;
	cout << *ptr;
	ptr = &l;
	cout << *ptr;
	cout << *ptr;
	ptr = &i;
	cout << *ptr;
	cout << endl;
}

struct T_Morse_Data
{
	char letter;
	std::string morse_code;
};
const T_Morse_Data morse_data[] = {
{ 'a', ".-" },
{ 'b', "-..." },
{ 'c', "-.-." },
{ 'd', "-.." },
{ 'e', "." },
{ 'f', "..-." },
{ 'g', "--." },
{ 'h', "...." },
{ 'i', ".." },
{ 'j', ".---" },
{ 'k', "-.-" },
{ 'l', ".-.." },
{ 'm', "--" },
{ 'n', "-." },
{ 'o', "---" },
{ 'p', ".--." },
{ 'q', "--.-" },
{ 'r', ".-." },
{ 's', "..." },
{ 't', "-" },
{ 'u', "..-" },
{ 'v', "...-" },
{ 'w', ".--" },
{ 'x', "-..-" },
{ 'y', "-.--" },
{ 'z', "--.." },
{ '0', "-----" },
{ '1', ".----" },
{ '2', "..---" },
{ '3', "...--" },
{ '4', "....-" },
{ '5', "....." },
{ '6', "-...." },
{ '7', "--..." },
{ '8', "---.." },
{ '9', "----." },
// Leerzeichen zur Worttrennung werden im Morsecode
// durch einen Slash '/' umgeben von Leerzeichen
// dargestellt ...
// (Alternative: Trennung durch 3 Leerzeichen)
// Hier bei uns, um die Testläufe eindeutiger zu
// machen: Trennung mittels drei Slashes
{ ' ', "///" },
{ '.', ".-.-.-" },
{ ',', "--..--" },
{ ':', "---..." },
{ '?', "..--.." },
{ '-', "-....-" },
{ '/', "-..-." },
{ '@', ".--.-." },
{ '=', "-...-" }
};
const int morse_data_len = 47;
void O07_03()
{
	string text = "";
	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, text);
	for (int i = 0; i < text.length(); i++)
	{
		if (text.at(i) >= 'A' && text.at(i) <= 'Z')
		{
			text.at(i) = text.at(i) + 'a' - 'A';
		}
		for (int j = 0; j < morse_data_len; j++)
		{
			if (text.at(i) == morse_data[j].letter)
			{
				cout << morse_data[j].morse_code << '#';
				break;
			}
		}
	}
	cout << endl;

}