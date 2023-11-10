#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            int x = rand() % n;
            x++;

            if (st.find(x) == st.end())
            {
                st.insert(x);
                cout << x << " ";
                break;
            }
        }
    }
    return 0;
}