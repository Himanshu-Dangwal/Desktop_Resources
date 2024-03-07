
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
vector<int> ans(MAX, 0);

void sieve()
{
    vector<bool> arr(MAX, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i * i < MAX; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                arr[j] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i < MAX; i++)
    {
        if (arr[i])
        {
            ans[i] = ans[i - 1] + 1;
        }
        else
        {
            ans[i] = ans[i - 1];
        }
    }
}

int main()
{

    sieve();
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        cout << (ans[r] - ans[l - 1]) << endl;
    }

    return 0;
}