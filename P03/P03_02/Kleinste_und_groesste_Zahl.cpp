#include <iostream>
using namespace std;

int main()
{
	int last, min, minPos, max, maxPos = 1;

	for (int i = 0; i < 5; i++)
	{
		cout << "Please provide integer " << i+1 << " out of 5: ";
		cin >> last;
		if (i == 0)
		{
			min = last;
			max = last;
		}
		else
		{
			if (last < min)
			{
				min = last;
				minPos = i + 1;
			}
			else if (last > max)
			{
				max = last;
				maxPos = i + 1;
			}
		}
	}
	cout << "Maximum: " << max << " at position " << maxPos << endl;
	cout << "Minimum: " << min << " at position " << minPos << endl;
	system("pause");
	return 0;
}