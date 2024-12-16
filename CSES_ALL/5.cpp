#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<int,int>
#define f first 
#define s second
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


int main()
{
    int n;
    cin >> n;

    if (n == 0) {
        cout << "0";
        return 0;
    }

    queue<pii> q;
    q.push({ 1,1 });
    q.push({ -1,1 });

    set<pii> st;
    st.insert({ 1,1 });
    st.insert({ -1,1 });

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.f == n) {
            cout << curr.s;
            return 0;
        }

        if (st.find({ curr.f + curr.s + 1,curr.s + 1 }) == st.end())
            q.push({ curr.f + curr.s + 1,curr.s + 1 });

        if (st.find({ curr.f - curr.s - 1,curr.s + 1 }) == st.end())
            q.push({ curr.f - curr.s - 1,curr.s + 1 });
    }

    return 0;
}