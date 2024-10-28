#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll N, K, L;
    cin >> N >> K >> L;

    ll i = 1;
    ll x1 = i * K - L;
    ll x2 = i * K + L;
    ll y1 = i * K - L;
    ll y2 = i * K + L;


    ll s = x2 - x1;
    ll areaSingle = s * s;
    ll areaRed;
    ll totalArea;
    if (K >= s) {
        areaRed = 0;
        totalArea = areaSingle * N;
    }
    else {
        areaRed = areaSingle - (s - K) * (s - K);
        totalArea = areaSingle + (N - 1) * areaRed;
    }

    cout << totalArea << endl;

}