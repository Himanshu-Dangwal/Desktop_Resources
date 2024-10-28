#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


int main()
{
    vector<int> p;
    for (int i = 0;i < 3;i++) {
        p.push_back(i + 1);
    }

    do {
        for (int i = 0;i < 3;i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    } while (next_permutation(p.begin(), p.end()));
    return 0;
}