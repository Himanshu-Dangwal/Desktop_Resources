#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void count_divisors(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                cnt++;
                break;
            }
            cnt += 2;
        }
    }

    cout << cnt << endl;
}

vector<int> divi(1000000, 1);

void preComputeDivisors(int n)
{

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divi[j] += 1;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    // int cnt = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         cnt++;
    //     }
    // }
    // cout << cnt << endl;
    // cnt = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     count_divisors(i);
    // }

    preComputeDivisors(n);

    for (int i = 1; i <= n; i++)
    {
        cout << divi[i] << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}