#include "CharListenKnoten.h"

//void CharListenKnoten::append(char data)
//{	// Append as last
//	CharListenKnoten* ptr = this;
//	while (ptr->next != nullptr)
//	{
//		ptr = ptr->next;
//	}
//	ptr->next = new CharListenKnoten(data);
//}

void CharListenKnoten::append(char data)
{	// Append as last
	if (next)
		next->append(data);
	else
		next = new CharListenKnoten(data);
}