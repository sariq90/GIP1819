#include <iostream>
#include <string>
#include "wortspiegel.h"
using namespace std;

void wortspiegel(string &text, int pos)
{
	int len = text.length();
	int lpos = pos;
	int rpos = pos;
	string word = "";

	//Find the brackets for the word, check if string ended or terminations were overstepped.
	while (lpos > 0 && text[lpos] != ' ' && text[lpos] != '.')
	{
		lpos--;
	}
	if (text[lpos] == ' ' || text[lpos] == '.')
	{
		lpos++;
	}
	while (rpos < len-1 && text[rpos] != ' ' && text[rpos] != '.')
	{
		rpos++;
	}
	if (text[rpos] == ' ' || text[rpos] == '.')
	{
		rpos--;
	}

	//Swapperino, ignore one char-words.
	if (rpos - lpos > 0)
	{
		for (int i = rpos; i >= lpos; i--)
		{ //Load word with inverted text from brackets.
			word = word + text[i];
		}
		for (int i = 0; i < word.length(); i++)
		{ //Unleash inverted word in all its glory.
			text[lpos + i] = word[i];
		}
	}

}

void wortwahl(string &text)
{
	int len = text.length();
	char input = 'a';
	int pos = 0;

	do
	{
		//Position of *-marker on screen.
		cout << text << endl;
		for (int i = 0; i < pos; i++)
		{
			cout << " ";
		}
		cout << "*"<< endl << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";
		cin >> input;
		cin.clear();
		cin.ignore(1000, '\n');
		if (input == 'l' && pos > 0)
		{
			pos--;
		}
		else if (input == 'r' && pos < len - 1)
		{
			pos++;
		}
		else if (input == 's' && pos != '*' && pos != ' ')
		{ //Call the ghostbusters. I mean wordswappers.
			wortspiegel(text, pos);
		}
	} while (input != 'q');

}