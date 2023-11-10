//[C++]
#include <bits/stdc++.h>

using namespace std;

int bFromA(int n, int m, string a, string b)
{

	// Creating two hashmaps 'mp1' and 'mp2' of [key, value] as [char, int].
	unordered_map<char, int> mp1, mp2;

	// Calculating occurrences of characters in 'a' and 'b'.
	for (int i = 0; i < n; i++)
	{
		mp1[a[i]]++;
	}
	for (int i = 0; i < m; i++)
	{
		mp2[b[i]]++;
	}

	// Initializing 'ans' with 1e9.
	int ans = 1e9;

	for (auto i : mp2)
	{
		int x = i.second;
		int y = mp1[i.first];
		ans = min(ans, y / x);
	}

	// We are returning the answer here.
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		string a, b;
		cin >> a;
		cin >> b;
		cout << bFromA(n, m, a, b) << "\n";
	}
}