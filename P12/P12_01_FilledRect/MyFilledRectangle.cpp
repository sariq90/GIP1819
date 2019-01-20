#include "MyFilledRectangle.h"
#include "CImgGIP05.h"

void MyFilledRectangle::draw()
{
	MyRectangle::draw();

	if (x2 - x1 < 5 || y2 - y1 < 5)
	{	// Prüfe, ob 2px-Abstand erfüllt ist
		return;
	}
	else
	{
		for (int y = y1 + 2; y <= y2 - 2; y++)
		{
			gip_draw_line(x1+2, y, x2-2, y, red);
		}
		return;
	}
}