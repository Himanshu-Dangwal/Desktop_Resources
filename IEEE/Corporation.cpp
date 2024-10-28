#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n, q;
    cin >> n >> q;


    vector<ll> arr(n + 1), happiness(n + 1, 0);
    for (int i = 1;i <= n;cin >> arr[i++]);

    while (q--) {
        int type;
        cin >> type;

        if (type == 0) {
            ll l, r, c;
            cin >> l >> r >> c;

            for (int i = l;i <= r;i++) {
                if (c > arr[i]) {
                    happiness[i] += 1;
                }
                else if (c < arr[i]) {
                    happiness[i] -= 1;
                }
                arr[i] = c;
            }
        }
        else if (type == 1) {
            ll l, r, c;
            cin >> l >> r >> c;
            if (c > 0) {
                for (int i = l;i <= r;i++) {
                    happiness[i] += 1;
                }
            }
            else if (c < 0) {
                for (int i = l;i <= r;i++) {
                    happiness[i] -= 1;
                }
            }
            for (int i = l;i <= r;i++) {
                arr[i] += c;
            }
        }
        else if (type == 2) {
            ll l, r;
            cin >> l >> r;

            ll sum = 0;
            for (int i = l;i <= r;i++) {
                sum += arr[i];
            }
            ll tot = r - l + 1;
            ll gcd = __gcd(sum, tot);
            sum /= gcd;
            tot /= gcd;

            cout << sum << "/" << tot << endl;
        }
        else {
            ll l, r;
            cin >> l >> r;
            ll sum = 0;
            for (int i = l;i <= r;i++) {
                sum += happiness[i];
            }
            ll tot = r - l + 1;
            ll gcd = __gcd(sum, tot);
            sum /= gcd;
            tot /= gcd;

            cout << sum << "/" << tot << endl;
        }
    }
}