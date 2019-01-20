#include "MyRectangle.h"
#include "CImgGIP05.h"

void MyRectangle::set(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void MyRectangle::draw()
{
	gip_draw_rectangle(x1, y1, x2, y2, blue);
}

bool MyRectangle::does_not_collide_with(const MyRectangle& other)
{
	if (other.x1 > this->x2 || other.x2 < this->x1 || other.y1 > this->y2 || other.y2 < this->y1)
	{
		return true;
	}
	else
	{
		return false;
	}
}