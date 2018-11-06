//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string text = "";
//	bool flawed = false;
//	bool palindrom = true;
//	
//	do
//	{
//		flawed = false;
//		cout << "Text: ? ";
//		getline(cin, text);
//		for (int i = 0; i < text.length(); i++)
//		{
//			if (text.at(i) < 'a' || text.at(i) > 'z')
//			{
//				flawed = true;
//				break;
//			}
//		}
//	} while (flawed || text == "");
//
//	for (int i = 0; i < text.length() / 2; i++)
//	{
//		if (text.at(i) != text.at(text.length() - 1 - i))
//		{
//			palindrom = false;
//			break;
//		}
//	}
//
//	if (palindrom)
//	{
//		cout << "Das eingegebene Wort ist ein Palindrom." << endl;
//	}
//	else
//	{
//		cout << "Das eingegebene Wort ist KEIN Palindrom." << endl;
//	}
//	
//	system("PAUSE");
//	return 0;
//}