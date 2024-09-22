#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> jobs(n + 2, 0);
    for (int i = 0; i < k; i++)
    {
        int start, end;
        cin >> start >> end;
        int mini = (start - d + 1 < 1) ? 1 : (start - d + 1);

        jobs[mini] += 1;
        jobs[end + 1] -= 1;
    }

    for (int i = 1; i <= n + 1; i++)
    {
        jobs[i] += jobs[i - 1];
    }

    int mini = INT_MAX, maxi = INT_MIN;
    int first = 1, second = 1;

    // if (k == 4)
    // {
    //     for (int x : jobs)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n - d + 1; i++)
    {
        if (jobs[i] < mini)
        {
            mini = jobs[i];
            first = i;
        }

        if (jobs[i] > maxi)
        {
            maxi = jobs[i];
            second = i;
        }
    }

    cout << second << " " << first << endl;
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