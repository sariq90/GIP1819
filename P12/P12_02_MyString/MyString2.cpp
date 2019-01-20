#include "MyString2.h"

MyString2::MyString2(std::string s) : anker{ nullptr }
{	// Construct from string
	if (s.length() == 0)
	{
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		append_internal(s[i]);
	}
}
// Hidden Methods
void MyString2::append_internal(char p_data)
{	
	if (this->anker == nullptr)
	{
		anker = new CharListenKnoten(p_data);
		return;
	}
	anker->CharListenKnoten::append(p_data);
}

void MyString2::delete_internal()
{
	CharListenKnoten* ptr = anker;
	while (ptr != nullptr)
	{
		CharListenKnoten* next = ptr->get_next();
		delete ptr;
		ptr = next;
	}
	anker = nullptr;
}

CharListenKnoten* MyString2::deep_copy_internal() const
{
	if (anker == nullptr)
	{
		return nullptr;
	}
	CharListenKnoten* copy = new CharListenKnoten(anker->get_data());
	CharListenKnoten* ptr = anker->get_next();
	while (ptr != nullptr)
	{
		copy->append(ptr->get_data());
		ptr = ptr->get_next();
	}
	return copy;
}
// Public Methods
MyString2::~MyString2()
{
	delete_internal();
}

MyString2::MyString2(const MyString2& original) : anker{ nullptr }
{
	anker = original.deep_copy_internal();
}

unsigned int MyString2::length()
{
	unsigned int count = 0;
	CharListenKnoten* ptr = anker;
	while (ptr != nullptr)
	{
		ptr = ptr->get_next();
		count++;
	}
	return count;
}

char MyString2::at(unsigned int pos)
{
	if (pos >= length())
	{
		return '\0';
	}
	CharListenKnoten* ptr = anker;
	for (int i = 0; i < pos; i++)
	{
		ptr = ptr->get_next();
	}
	return ptr->get_data();
}

std::string MyString2::to_string() const
{
	std::string s = "";
	CharListenKnoten* ptr = anker;
	while (ptr != nullptr)
	{
		s += ptr->get_data();
		ptr = ptr->get_next();
	}
	return s;
}

MyString2& MyString2::operator =(const MyString2& original)
{
	delete_internal();
	anker = original.deep_copy_internal();
	return *this;
}

MyString2 MyString2::operator +(char c) const
{
	MyString2 copy = *this;		// Copy-Constructor
	copy.append_internal(c);
	return copy;
}