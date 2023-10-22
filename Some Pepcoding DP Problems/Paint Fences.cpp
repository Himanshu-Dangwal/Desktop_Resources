// Paint Fence::
/*
	Given n fence and we have  K colour. We  have to found all the ways to paint those n fences such that no more than 2 consecutive
	fences have the same colour::
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	cout << endl;
	if (n == 1)
	{
		cout << k << endl;
		exit(0);
	}
	int same = k;
	int diff = k * (k - 1);
	int total = same + diff;

	for (int i = 3; i <= n; i++)
	{
		same = diff;
		diff = total * (k - 1);
		total = same + diff;
	}
	cout << total << endl;
	return 0;
}
