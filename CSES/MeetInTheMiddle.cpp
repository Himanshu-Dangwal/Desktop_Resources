// #include <bits/stdc++.h>
// using namespace std;
// // #pragma GCC target("popcnt")
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;
// // #include <ext/pb_ds/assoc_container.hpp>
// // using namespace __gnu_pbds;
// // typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// // find_by_order() 
// // order_of_key()


// int main()
// {
//     ll n, x;
//     cin >> n >> x;
//     int sz1 = n / 2;
//     int sz2 = n - sz1;
//     vector<int> arr1(sz1), arr2(sz2);
//     unordered_map<ll, ll> mp1, mp2;

//     for (int i = 0;i < sz1;i++) {
//         cin >> arr1[i];
//     }

//     for (int i = 0;i < sz2;i++) {
//         cin >> arr2[i];
//     }

//     for (int i = 0;i < (1 << sz1);i++) {
//         ll currSum = 0;
//         for (int j = 0;j < sz1;j++) {
//             if ((i >> j) & 1) currSum += arr1[j];
//         }
//         mp1[currSum]++;
//     }

//     for (int i = 0;i < (1 << sz2);i++) {
//         ll currSum = 0;
//         for (int j = 0;j < sz2;j++) {
//             if ((i >> j) & 1) currSum += arr2[j];
//         }
//         mp2[currSum]++;
//     }

//     ll ans = 0;
//     for (auto it : mp1) {
//         int X = it.first;
//         if (mp2.find(x - X) != mp2.end()) {
//             ans += (it.second) * (mp2[x - X]);
//         }
//     }
//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;

// void generateSubsetSums(vector<int>& arr, unordered_map<ll, int>& sumMap) {
//     int n = arr.size();
//     for (int i = 0; i < (1 << n); i++) {
//         ll currSum = 0;
//         for (int j = 0; j < n; j++) {
//             if ((i >> j) & 1) currSum += arr[j];
//         }
//         sumMap[currSum]++;
//     }
// }

// int main()
// {
//     ll n, x;
//     cin >> n >> x;
//     int sz1 = n / 2;
//     int sz2 = n - sz1;

//     vector<int> arr1(sz1), arr2(sz2);
//     for (int i = 0; i < sz1; i++) cin >> arr1[i];
//     for (int i = 0; i < sz2; i++) cin >> arr2[i];

//     unordered_map<ll, int> mp1;
//     generateSubsetSums(arr1, mp1);

//     vector<ll> subsetSums2;
//     int n2 = arr2.size();
//     for (int i = 0; i < (1 << n2); i++) {
//         ll currSum = 0;
//         for (int j = 0; j < n2; j++) {
//             if ((i >> j) & 1) currSum += arr2[j];
//         }
//         subsetSums2.push_back(currSum);
//     }

//     sort(subsetSums2.begin(), subsetSums2.end());

//     ll ans = 0;
//     for (auto& it : mp1) {
//         ll required = x - it.first;
//         auto range = equal_range(subsetSums2.begin(), subsetSums2.end(), required);
//         ans += it.second * distance(range.first, range.second);
//     }

//     cout << ans << endl;
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 40;

int N, t[maxN];
ll x, sum, cnt;
unordered_map<ll, int> freq;

int main() {
    scanf("%d %lld", &N, &x);
    for (int i = 0; i < N; i++)
        scanf("%d", &t[i]);
    sort(t, t + N);

    if (N == 1) {
        printf("%d\n", x == t[0]);
        return 0;
    }

    freq.reserve(1 << (N / 2 - 1));
    for (int i = 0; i < (1 << (N / 2 - 1)); i++) {
        sum = 0;
        for (int j = 0; j < N / 2 - 1; j++)
            if (i & (1 << j))
                sum += t[j];
        freq[sum]++;
    }

    for (int i = 0; i < (1 << ((N + 1) / 2 + 1)); i++) {
        sum = 0;
        for (int j = 0; j < (N + 1) / 2 + 1; j++)
            if (i & (1 << j))
                sum += t[N / 2 - 1 + j];
        if (freq.find(x - sum) != freq.end())
            cnt += freq[x - sum];
    }

    printf("%lld\n", cnt);
}