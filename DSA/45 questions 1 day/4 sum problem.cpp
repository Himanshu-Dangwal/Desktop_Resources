// Four sum problem:::
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int target;
	cin >> target;

	sort(arr, arr + n);
	vector<vector<int>> res;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int two_sum = target - arr[i] - arr[j];
			int left = j + 1;
			int right = n - 1;

			while (left < right)
			{
				if (arr[left] + arr[right] < two_sum)
				{
					left++;
				}
				else if (arr[left] + arr[right] > two_sum)
				{
					right--;
				}
				else
				{
					vector<int> quadruple(4, 0);
					quadruple[0] = arr[i];
					quadruple[1] = arr[j];
					quadruple[2] = arr[left];
					quadruple[3] = arr[right];

					res.push_back(quadruple);

					while (left < right && arr[left] == quadruple[2])
						left++;
					while (left < right && arr[right] == quadruple[3])
						right--;
				}
			}
			while (j + 1 < n && arr[j] == arr[j + 1])
				j++;
		}
		while (i + 1 < n && arr[i] == arr[i + 1])
			i++;
	}
	cout << endl;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
