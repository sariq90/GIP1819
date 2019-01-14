#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
using namespace cimg_library;

const int grid_size = 30; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size = 18;  // size der einzelnen Kaestchen (in Pixel)
const int border = 20;    // Rand links und oben bis zu den ersten Kaestchen (in Pixel)

// Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(bool grid[][grid_size]);

int main()
{
	bool grid[grid_size][grid_size] = { 0 };
	bool next_grid[grid_size][grid_size] = { 0 };

	// Erstes Grid vorbelegen ...
	grid_init(grid);

	while (gip_window_not_closed())
	{
		// Spielfeld anzeigen ...
		gip_stop_updates();
		//Boxsize, Abstand!
		for (int y = 0; y < grid_size; y++)
		{
			for (int x = 0; x < grid_size; x++)
			{
				if (grid[x][y] == true)
				{
					gip_color rnd = {gip_random(50,255),gip_random(50,255),gip_random(50,255)};
					gip_draw_rectangle(x*box_size + border, y*box_size + border, (x + 1)*box_size + border, (y + 1)*box_size + border, rnd);
				}
				else
				{
					gip_draw_rectangle(x*box_size + border, y*box_size + border, (x + 1)*box_size + border, (y + 1)*box_size + border, black);
				}
			}
		}

		gip_start_updates();
		gip_sleep(1);
		

		// Berechne das naechste Spielfeld ...
		// Achtung; Für die Zelle (x,y) darf die Position (x,y) selbst *nicht*
		// mit in die Betrachtungen einbezogen werden.
		// Ausserdem darf bei zellen am rand nicht über den Rand hinausgegriffen
		// werden (diese Zellen haben entsprechend weniger Nachbarn) ...


		// Nachbarberechnung, Sonderbehandlung für Ecken und Kanten
		for (int y = 0; y < grid_size; y++)
		{
			for (int x = 0; x < grid_size; x++)
			{
				int x_s = x - 1, x_e = x + 1, y_s = y - 1, y_e = y + 1, c = 0;	// Loop-Limits-Init
				if (x == 0)
				{	// links
					x_s = x;
				}
				else if (x == grid_size - 1)
				{	// rechts
					x_e = x;
				}
				if (y == 0)
				{	// oben
					y_s = y;
				}
				else if (y == grid_size - 1)
				{	// unten
					y_e = y;
				}

				for (int i = x_s; i <= x_e; i++)
				{
					for (int j = y_s; j <= y_e; j++)
					{
						if (i == x && j == y)
						{
							continue;
						}
						if (grid[i][j])
						{
							c++;
						}
					}
				}

				if (c == 3 || (grid[x][y] == true && c == 2))
				{	// LIVE...
					next_grid[x][y] = true;
				}
				else
				{	// OR DIE.
					next_grid[x][y] = false;
				}
			}
		}

		// Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...

		// Refresh
		for (int y = 0; y < grid_size; y++)
		{
			for (int x = 0; x < grid_size; x++)
			{
				grid[x][y] = next_grid[x][y];
			}
		}

	}
	return 0;
}

void grid_init(bool grid[][grid_size])
{
	int eingabe = -1;
	do {
		cout << "Bitte waehlen Sie die Vorbelegung des Grids aus:" << endl
			<< "0 - Zufall" << endl
			<< "1 - Statisch" << endl
			<< "2 - Blinker" << endl
			<< "3 - Oktagon" << endl
			<< "4 - Gleiter" << endl
			<< "5 - Segler 1 (Light-Weight Spaceship)" << endl
			<< "6 - Segler 2 (Middle-Weight Spaceship)" << endl
			<< "? ";
		cin >> eingabe;
		cin.clear();
		cin.ignore(1000, '\n');
	} while (eingabe < 0 || eingabe > 6);

	if (eingabe == 0)
	{
		// Erstes Grid vorbelegen (per Zufallszahlen) ...
		
		for (int y = 0; y < grid_size; y++)
		{
			for (int x = 0; x < grid_size; x++)
			{
				grid[x][y] = gip_random(0,1);
			}
		}

	}
	else if (eingabe == 1)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '*', '.', '*' },
			{ '.', '*', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 2)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '.', '*', '.' },
			{ '.', '*', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 3)
	{
		const int pattern_size = 8;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 1] = true;
	}
	else if (eingabe == 4)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '.', '.', '*' },
			{ '*', '*', '*' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 5)
	{
		const int pattern_size = 5;
		char pattern[pattern_size][pattern_size] =
		{
			{ '*', '.', '.', '*', '.' },
			{ '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*' },
			{ '.', '*', '*', '*', '*' },
			{ '.', '.', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 6)
	{
		const int pattern_size = 6;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '*', '*', '*', '*' },
			{ '*', '.', '.', '.', '.', '*' },
			{ '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '.' },
			{ '.', '.', '.', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
}

