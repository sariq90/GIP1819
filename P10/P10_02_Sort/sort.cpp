#include "sort.h"

void sortiere(int a[], const int N)
{
	for (int i = 1; i < N; i++)
	{
		int einzusortieren = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > einzusortieren)
		{
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = einzusortieren;
	}
}