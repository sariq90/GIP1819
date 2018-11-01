#include <iostream>
using namespace std;

int main()
{
//Note: Doesn't work with negative integers, because the "-" assumes one of the char slots. 
//("-" has an ASCII value of 45, it follows 45 - 48 is always -3.)
	char c1 = 'a', c2 = 'a';
	int a = 0;
	int b = 0;
	int sum = 0;

	cout << "Please provide two integers (press 'q' to abort): ";
	cin >> c1 >> c2;
	if (c1 == 'q' || c2 == 'q' || c1 == 'Q' || c2 == 'Q')
	{
		cout << "Program aborted. ABANDON SHIP.\n";
		system("pause");
		return 1;
	}
	a = int(c1) - int('0');
	b = int(c2) - int('0');
	sum = a + b;
	cout << a << " + " << b << " = " << sum << endl;

	system("pause");
	return 0;
}