#include <string>

void spalte_ab_erstem(char zeichen,	std::string eingabe, std::string& erster_teil, std::string& zweiter_teil)
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

std::string trimme(std::string s, char z = ' ')
{
	int length = s.length();
	int clampL = 0;
	int clampR = 0;
	std::string output = "";

	for (int i = 0; i < length; i++)
	{
		if (s[i] != z)
		{
			clampR = i + 1;
		}
		if (s[length - 1 - i] != z)
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

std::string ersetze(std::string zeile, char zu_ersetzendes_zeichen, std::string ersatztext)
{
	std::string output = "";
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

std::string fett(std::string s)
{
	s = "<b>" + s + "</b>";
	return s;
}
