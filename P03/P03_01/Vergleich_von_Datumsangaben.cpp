#include <iostream>
using namespace std;

int main()
{
	int day1, day2, month1, month2, year1, year2 = 0;

	cout << "Insert first date (D M Y): ";
	cin >> day1 >> month1 >> year1;
	cout << "Insert second date (D M Y): ";
	cin >> day2 >> month2 >> year2;

	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if (day1 == day2)
			{
				cout << "The dates are identical.";
			}
			else if (day1 < day2)
			{
				cout << "Date 1 comes before date 2.";
			}
			else
			{
				cout << "Date 2 comes before date 1.";
			}
		}
		else if (month1 < month2)
		{
			cout << "Date 1 comes before date 2.";
		}
		else
		{
			cout << "Date 2 comes before date 1.";
		}
	}
	else if (year1 < year2)
	{
		cout << "Date 1 comes before date 2.";
	}
	else
	{
		cout << "Date 2 comes before date 1.";
	}

	cout << endl;
	system("pause");
	return 0;
}