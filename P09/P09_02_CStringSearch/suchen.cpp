#include "suchen.h"

int zeichenkette_suchen(const char* text, const char* zkette)
{
	if (text[0] == '\0')
	{	// Abbruch: text ist leer
		return -1;
	}

	int pos = -1;
	bool check = false;

	for (int i = 0, j = 0; i < 20; i++)
	{
		if (text[i] == zkette[0] && j == 0)
		{	// Erste char-Übereinstimmung gefunden
			check = true;
			pos = i;
			j++;
		}
		else if (text[i] == zkette[j] || zkette[j] == '\0')
		{
			if (zkette[j] == '\0')
			{	// Abbruch: zkette zu Ende
				break;
			}	// Sonst: Nächsten char überprüfen
			j++;
		}
		else if (text[i] == '\0')
		{	// Abbruch: text zu Ende, zkette aber nicht
			check = false;
			break;
		}
		else
		{	// Sonst: Keine Übereinstimmung, reset ehemaliger Übereinstimmungen
			check = false;
			j = 0;
		}
	}
	if (check == true)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}

