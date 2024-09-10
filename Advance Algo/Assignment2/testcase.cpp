#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    cout << n << endl;

    srand(time(NULL));
    unordered_set<int> st;
    for (int i = 0; i < n;)
    {
        int x = rand() % 1000 + 1;
        if (st.find(x) == st.end())
        {
            st.insert(x);
            cout << x << " ";
            i++;
        }
    }
    return 0;
}