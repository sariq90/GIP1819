#include "binaerer_suchbaum.h"
#include <iostream>


namespace suchbaum
{
	void einfuegen(BaumKnoten *&anker, int wert)
	{	// Rekursive Funktion zum Einfügen in einen duplikatfreien Binärbaum
		if (anker == nullptr)
		{	// Falls eine leere Position im Baum erreicht wurde, erstelle neuen Knoten und initiiere Felder
			BaumKnoten *neuer = new BaumKnoten;
			neuer->data = wert;
			neuer->parent = nullptr;
			neuer->left = nullptr;
			neuer->right = nullptr;
			anker = neuer;
		}
		else if (wert < anker->data)
		{	// Bei Knotenbelegung: Linksabzweigung. Setze parent nach Stackabbau
			einfuegen(*&anker->left, wert);
			anker->left->parent = anker;
		}
		else if (wert > anker->data)
		{	// Analoge Rechtsabzweigung für kleinere Knotenwerte
			einfuegen(*&anker->right, wert);
			anker->right->parent = anker;
		}
	}
	void ausgeben(BaumKnoten *anker)
	{	//Rekursive Ausgabefkt.
		if (anker == nullptr)
		{	// Sonderbehandlung leerer Baum
			std::cout << "Leerer Baum.\n";
		}
		else
		{
			int tiefe = 0;
			BaumKnoten *ptr = anker;
			while (ptr->parent != nullptr)
			{	// Finde Tiefe heraus, indem parent-ptr bis zum anker gefolgt werden
				tiefe++;
				ptr = ptr->parent;
			}
			ptr = anker;
			if (ptr->right != nullptr)
			{	// Wenn rechts belegt ist, rufe Fkt rekursiv auf
				ausgeben(ptr->right);
			}
			knoten_ausgeben(ptr, tiefe); // Gibt Knoten aus, sobald rechts keiner mehr ist
			if (ptr->left == nullptr)
			{	// Ist links auch keiner, dann zurück
				return;
			}
			else
			{	// Gehts links weiter, dann rufe Fkt rekursiv auf
				ausgeben(ptr->left);
			}
		}
	}
	void knoten_ausgeben(BaumKnoten* knoten, int tiefe)
	{	// Funktion zum plotten der Knoten
		for (int i = 0; i < 2 * tiefe; i++)
		{
			std::cout << "+";
		}
		std::cout << knoten->data << std::endl;
	}
}
