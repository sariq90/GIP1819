//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string text = "";
//	string cinput = " ";
//	int pos = -1;
//
//
//	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
//	getline(cin, text);
//	cout << "Bitte Buchstaben eingeben: ? ";
//	getline(cin, cinput);
//	char c = cinput[0];
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		if (text.at(i) == c)
//		{
//			pos = i;
//		}
//	}
//
//	if (pos == -1)
//	{
//		cout << "Der Buchstabe " << c << " kommt nicht im Text vor." << endl;
//	}
//	else
//	{
//		cout << "Der Buchstabe " << c << " kommt im Text vor, an Position " << pos << "." << endl;
//	}
//	
//	system("PAUSE");
//	return 0;
//}