#include <bits/stdc++.h>
using namespace std;

int solve(int k)
{
    int low = 0, high = k;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int equationValue = 2 * mid * mid + 5 * mid;

        if (equationValue == k)
        {
            return mid;
        }
        else if (equationValue < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int k;
    cin >> k;

    int result = solve(k);

    if (result != -1 && result != 0)
    {
        cout << result << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}
