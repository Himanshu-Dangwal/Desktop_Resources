// Modified Power Function

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007

ll power(ll x, ll y)
{
	if (x == 0)
	{
		return 0;
	}
	if (y == 0)
	{
		return 1;
	}
	ll ans;
	if (y % 2 == 0)
	{
		ll val = power(x, y / 2);
		ans = ((val) % MOD * (val) % MOD) % MOD;
	}
	else
	{
		ll val = power(x, y / 2);
		ans = ((val) % MOD * (val) % MOD * (x) % MOD) % MOD;
	}
	return ans;
}

int main()
{
	ll x, y;
	cin >> x >> y;
	// To find power(x,y) i.e  x^y ::
	cout << power(x, y);
	return 0;
}
