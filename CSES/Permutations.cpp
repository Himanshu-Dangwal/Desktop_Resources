#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "1";
        return 0;
    }

    if (n <= 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    int odd = n / 2;
    if (n % 2)
        odd++;
    int even = n / 2;

    int evenVal = 2;
    for (int i = 1; i <= even; i++)
    {
        cout << evenVal << " ";
        evenVal += 2;
    }

    int oddVal = 1;
    for (int i = 1; i <= odd; i++)
    {
        if (i == odd)
        {
            cout << oddVal;
            break;
        }
        cout << oddVal << " ";
        oddVal += 2;
    }

    return 0;
}