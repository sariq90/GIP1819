#pragma once

class CharListenKnoten
{
protected:
	// Attributes
	char data;
	CharListenKnoten* next;

public:
	// Constructors
	CharListenKnoten() : data{ 0 }, next{ nullptr } {}
	CharListenKnoten(char c) : data{ c }, next { nullptr } {}
	// Getters
	char get_data() { return data; }
	CharListenKnoten* get_next() const { return next; }
	// Setters
	void set_data(char c) { this->data = c; }
	void set_next(CharListenKnoten* n) { this->next = n; }
	// Method
	void append(char data);
};