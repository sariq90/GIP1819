#include <string>
#include "person.h"
#include "texte.h"

Person extrahiere_person(std::string eingabezeile)
{
	Person person;
	std::string rest = "";
	spalte_ab_erstem(',', eingabezeile, person.nachname, rest);
	spalte_ab_erstem(',', rest, person.vorname, person.geburtstag);
	person.vorname = trimme(person.vorname);
	person.geburtstag = trimme(person.geburtstag);
	return person;
}