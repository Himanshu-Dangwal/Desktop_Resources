#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void solve()
{
}

int main()
{
    int n;
    cin >> n;

    set<ll> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    cout << st.size();
    return 0;
}