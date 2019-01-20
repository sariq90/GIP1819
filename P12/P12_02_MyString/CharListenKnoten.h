#pragma once

class CharListenKnoten
{
protected:
	// Attributes
	char data;
	CharListenKnoten* next;
	
public:
	// Constructors
	CharListenKnoten() : data{ '\0' }, next{ nullptr } {}
	CharListenKnoten(char c, CharListenKnoten* n = nullptr) : data{ c }, next{ n } {}
	// Getters
	char get_data() { return data; }
	CharListenKnoten* get_next() const { return next; }
	// Setters
	void set_data(char c) { data = c; }
	void set_next(CharListenKnoten* n) { next = n; }
	// Method
	void append(char data);
};
