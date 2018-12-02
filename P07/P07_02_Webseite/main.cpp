#include <fstream>
#include <string>
#include "person.h"
#include "texte.h"
using namespace std;

int main()
{
	string kurztext = "";
	string langtext = "";
	string s = "";
	Person p;
	ifstream textfile("personendaten.txt");
	ifstream webtmpl("webseite.html.tmpl");
	ofstream web("webseite.html");

	while (bool(getline(textfile, s)))
	{	//Speichere zeilenweise Personen im Person-struct, konstruiere die ersetzenden Listen für später
		p = extrahiere_person(s);
		kurztext = kurztext + fett(p.nachname) + ", " + p.vorname + "<br/>\n";
		langtext = langtext + fett(p.vorname + " " + p.nachname) + ", " + p.geburtstag + "<br/>\n";
	}
	textfile.close();
	while (bool(getline(webtmpl, s)))
	{	//Platziere die Listen und schreibe den html-code zeilenweise in webseite.html
		s = ersetze(s, '%', kurztext);
		s = ersetze(s, '$', langtext);
		web << s << endl;
	}
	webtmpl.close();
	web.close();

	return 0;
}