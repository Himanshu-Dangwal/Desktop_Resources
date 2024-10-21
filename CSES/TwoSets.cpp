#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{

    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 == 0)
    {
        unordered_set<int> st;
        bool flag = false;
        ll currsum = 0;
        for (int i = n; i >= 1;)
        {
            currsum += i;
            st.insert(i);
            if (!flag)
            {
                i -= 3;
                flag = true;
            }
            else
            {
                i -= 1;
                flag = false;
            }
        }

        cout << "YES" << endl;
        cout << st.size() << endl;
        for (auto it : st)
            cout << it << " ";
        cout << endl;

        cout << n - st.size() << endl;
        for (int i = 1; i <= n; i++)
        {
            if (st.find(i) == st.end())
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}