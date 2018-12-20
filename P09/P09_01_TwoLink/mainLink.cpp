#include <iostream>
#include <string>
using namespace std;

struct TListenKnoten
{
	int data;
	TListenKnoten *next;
	TListenKnoten *prev;
};

void hinten_anfuegen(TListenKnoten *&anker, const int wert)
{
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		neuer_eintrag->prev = ptr;
		ptr->next = neuer_eintrag;

	}
}

void in_liste_einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert)
{
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert_neu;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten *ptr = anker;
		while (ptr != nullptr)
		{
			if (ptr->data == vor_wert)
			{
				if (ptr == anker)
				{	// Sonderbehandlung, wenn vor dem ersten Eintrag eingefügt wird
					neuer_eintrag->next = ptr;
					neuer_eintrag->prev = nullptr;
					ptr->prev = neuer_eintrag;
					anker = neuer_eintrag;
				}
				else
				{	// Setze erst Pointer des neuen Eintrags, danach die Pointer der umliegenden Knoten
					neuer_eintrag->next = ptr;
					neuer_eintrag->prev = ptr->prev;
					ptr->prev = neuer_eintrag;
					neuer_eintrag->prev->next = neuer_eintrag;
				}
				return;
			}
			else if (ptr->next == nullptr)
			{	// Sonderbehandlung für letzten Wert
				break;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		neuer_eintrag->prev = ptr;
		ptr->next = neuer_eintrag;
	}
}

string liste_als_string(TListenKnoten * anker)
{
	string resultat = "";
	if (anker == nullptr)
		return "Leere Liste."; // Zeile geändert !!!!!!!!!!!!!!
	else
	{
		resultat += "[ ";
		TListenKnoten *ptr = anker;
		do
		{
			resultat += std::to_string(ptr->data);
			if (ptr->next != nullptr) resultat += " , ";
			else resultat += " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
		resultat += "]";
	}
	return resultat;
}

void liste_ausgeben(TListenKnoten * anker)
{
	cout << liste_als_string(anker) << endl;
}

void liste_ausgeben_rueckwaerts(TListenKnoten * anker)
{
	string resultat = "";
	if (anker == nullptr)
		cout << "Leere Liste." << endl;
	else
	{
		resultat += "[ ";
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		do
		{
			resultat += std::to_string(ptr->data);
			if (ptr->prev != nullptr) resultat += " , ";
			else resultat += " ";
			ptr = ptr->prev;
		} while (ptr != nullptr);
		resultat += "]";
	}
	cout << resultat << endl;
}

void liste_loeschen(TListenKnoten* &anker)
{
	if (anker == nullptr)
	{
		return;
	}
	TListenKnoten *ptr = anker;
	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
		delete ptr->prev;
	}
	delete ptr;
	anker = nullptr;
}

int main()
{
	const int laenge = 10;
	TListenKnoten *anker = nullptr;
	liste_ausgeben(anker);
	liste_loeschen(anker);
	for (int i = 0; i < laenge; i++)
		in_liste_einfuegen(anker, i*i, 9999);
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);
	in_liste_einfuegen(anker, 99, 0);
	in_liste_einfuegen(anker, 99, 25);
	in_liste_einfuegen(anker, 99, 81);
	in_liste_einfuegen(anker, 99, 9999); // Achtung: geändert 99 => 9999
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);
	liste_loeschen(anker);
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);
	system("PAUSE");
	return 0;
}