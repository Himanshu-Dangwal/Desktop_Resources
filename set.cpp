#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);

    for (auto it : st)
    {
        cout << it << " ";
    }
}