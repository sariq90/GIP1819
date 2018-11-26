#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
int main()
{
	// F�r das "blaue Spielfeld" ...
	const int left_border = 100;
	const int right_border = 500;
	// F�r Ausdehnung und Position des wei�en Quadrats ...
	int x = 200, y = 300;
	const int rectangle_size = 50;
	int delta = 10;
	gip_white_background();
	while (gip_window_not_closed())
	{
		// Blaues "Spielfeld" neu zeichnen
		// (�bermalt dann auch das letzte wei�e Quadrat) ...
		gip_draw_rectangle(left_border, 100, // linke obere Ecke
			right_border, 500, // rechte untere Ecke
			blue);
		// Wei�es Quadrat neu zeichnen an der Position x,y ...
		gip_draw_rectangle(x, y, // linke obere Ecke
			x + rectangle_size, // rechte untere Ecke
			y + rectangle_size,
			white);
		// N�chste Position des wei�en Quadrats berechnen.
		// Dabei ber�cksichtigen, dass das Quadrat von den R�ndern des
		// blauen "Spielfelds" abprallen muss ...

		if (x + rectangle_size >= right_border || x <= left_border)
		{
			delta = -delta;
		}
		x = x + delta;

		gip_wait(100);
	}
	return 0;
}