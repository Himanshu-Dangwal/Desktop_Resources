// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;

// int main()
// {
//     int t;
//     int x, y;
//     cin >> x >> y;

//     cout << (x ^ y);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0;i < n;cin >> arr[i++]);

    unordered_set<int> st;
    for (int i = 0;i < n;i++) {
        if (st.find(target - arr[i]) != st.end()) {
            cout << target - arr[i] << " " << arr[i];
            return 0;
        }
        st.insert(arr[i]);
    }
    return 0;

}