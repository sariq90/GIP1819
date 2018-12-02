#pragma once
#include <string>

void spalte_ab_erstem(char zeichen, std::string eingabe, std::string& erster_teil, std::string& zweiter_teil);
std::string trimme(std::string s, char z = ' ');
std::string ersetze(std::string zeile, char zu_ersetzendes_zeichen, std::string ersatztext);
std::string fett(std::string s);