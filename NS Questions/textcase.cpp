#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "1000 1000" << endl;

    int n = 2000, m = 2000;
    set<int> st;
    int i = 1;
    while (n > 0)
    {

        int x = rand() % 100000;
        if (st.find(x) == st.end())
        {
            st.insert(x);
            if (i == 3)
                cout << endl, i = 1;
            cout << x << " ";
            i++;
            n--;
        }
    }

    cout << endl;
    set<int> st2;
    i = 1;
    while (m > 0)
    {
        int x = rand() % 100000;
        if (st2.find(x) == st2.end())
        {
            st2.insert(x);
            if (i == 3)
                cout << endl, i = 1;
            cout << x << " ";
            m--;
            i++;
        }
    }
}