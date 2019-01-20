#pragma once

class MyRectangle
{
protected:
	int x1, y1, x2, y2;

public:
	MyRectangle(int x1 = 0, int y1 = 0, int x2 = 20, int y2 = 20) : x1{ x1 }, y1{ y1 }, x2{ x2 }, y2{ y2 } {}

	int get_x1() const { return x1; }
	int get_x2() const { return x2; }
	int get_y1() const { return y1; }
	int get_y2() const { return y2; }
	void set_x1(int val) { x1 = val; }
	void set_x2(int val) { x2 = val; }
	void set_y1(int val) { y1 = val; }
	void set_y2(int val) { y2 = val; }
	void set(int x1, int y1, int x2, int y2);

	void draw();
	bool does_not_collide_with(const MyRectangle& other);
};