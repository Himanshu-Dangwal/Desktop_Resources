#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;
    unordered_set<int> st;
    for (int i = 0; i < n;)
    {
        int x = rand() % 10000000;
        if (st.find(x) == st.end())
        {
            cout << x << " ";
            st.insert(x);
            i++;
        }
    }
}