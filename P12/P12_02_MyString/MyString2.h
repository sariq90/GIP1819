#pragma once
#include "CharListenKnoten.h"
#include <string>

class MyString2
{
protected:
	// Attribute
	CharListenKnoten* anker;
	// Methods
	void append_internal(char p_data);
	void delete_internal();
	CharListenKnoten* deep_copy_internal() const;

public:
	// Constructors
	MyString2() : anker{ nullptr } {}
	MyString2(const std::string s);
	MyString2(const MyString2& original); // Copy-Constructor
	// Destructor
	~MyString2();
	// Operators
	MyString2& operator =(const MyString2& original);
	MyString2 operator +(char c) const;
	// Getter
	CharListenKnoten* get_anker() const { return anker; }
	// Setter
	void set_anker(CharListenKnoten* k) { anker = k; }
	// Methods
	unsigned int length();
	char at(unsigned int pos);
	std::string to_string() const;
	// Friends
	friend void friend_append_internal(MyString2& s, char p_data);
	friend void friend_delete_internal(MyString2& s);
	friend CharListenKnoten* friend_deep_copy_internal(MyString2& s);
};