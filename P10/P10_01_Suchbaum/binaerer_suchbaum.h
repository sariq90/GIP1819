#pragma once


namespace suchbaum
{
	struct BaumKnoten
	{
		int data;
		BaumKnoten *parent;
		BaumKnoten *left;
		BaumKnoten *right;
	};
	void einfuegen(BaumKnoten *&anker, int wert);
	void ausgeben(BaumKnoten *anker);
	void knoten_ausgeben(BaumKnoten* knoten, int tiefe);
}
