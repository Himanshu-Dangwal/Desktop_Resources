#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

const int maxN = 2e5 + 10;
ll n, q, ans;
vector<ll> arr(maxN), seg(4 * maxN), lazy(4 * maxN);

void buildTree(ll si, ll sj, ll segIdx) {
    if (si == sj) {
        seg[segIdx] = arr[si];
        return;
    }

    ll mid = (si + sj) / 2;
    buildTree(si, mid, 2 * segIdx + 1);
    buildTree(mid + 1, sj, 2 * segIdx + 2);
    seg[segIdx] = seg[2 * segIdx + 1] + seg[2 * segIdx + 2];
}

ll rangeQuery(int si, int sj, int segStart, int segEnd, int segIdx) {
    if (segEnd < si || segStart > sj) {
        return 0;
    }

    if (lazy[segIdx] != 0) {
        int cntOfElements = segEnd - segStart + 1;
        seg[segIdx] += cntOfElements * lazy[segIdx];
        if (segStart != segEnd) {
            lazy[2 * segIdx + 1] += lazy[segIdx];
            lazy[2 * segIdx + 2] += lazy[segIdx];
        }
        lazy[segIdx] = 0;
    }

    if (segStart >= si && segEnd <= sj) {
        return seg[segIdx];
    }

    ll mid = (segStart + segEnd) / 2;
    return (rangeQuery(si, sj, segStart, mid, 2 * segIdx + 1) + rangeQuery(si, sj, mid + 1, segEnd, 2 * segIdx + 2));
}

void pointQuery(int idx, int segStart, int segEnd, int segIdx) {
    if (lazy[segIdx] != 0) {
        seg[segIdx] += (segEnd - segStart + 1) * lazy[segIdx];
        if (segStart != segEnd) {
            lazy[2 * segIdx + 1] += lazy[segIdx];
            lazy[2 * segIdx + 2] += lazy[segIdx];
        }
        lazy[segIdx] = 0;
    }

    if (segStart == segEnd) {
        ans = seg[segIdx];
        return;
    }

    ll mid = (segStart + segEnd) / 2;
    if (idx <= mid) {
        pointQuery(idx, segStart, mid, 2 * segIdx + 1);
    }
    else {
        pointQuery(idx, mid + 1, segEnd, 2 * segIdx + 2);
    }
}

void update(int si, int sj, int val, int segStart, int segEnd, int segIdx) {
    if (lazy[segIdx] != 0) {
        int cntOfElements = segEnd - segStart + 1;
        seg[segIdx] += cntOfElements * lazy[segIdx];
        if (segStart != segEnd) {
            lazy[2 * segIdx + 1] += lazy[segIdx];
            lazy[2 * segIdx + 2] += lazy[segIdx];
        }
        lazy[segIdx] = 0;
    }

    if ((si > segEnd) || (sj < segStart)) return;

    if ((segStart >= si) && (segEnd <= sj)) {
        seg[segIdx] += (segEnd - segStart + 1) * val;
        if (segStart != segEnd) {
            lazy[2 * segIdx + 1] += val;
            lazy[2 * segIdx + 2] += val;
        }
        return;
    }

    ll mid = (segStart + segEnd) / 2;
    update(si, sj, val, segStart, mid, 2 * segIdx + 1);
    update(si, sj, val, mid + 1, segEnd, 2 * segIdx + 2);
    seg[segIdx] = seg[2 * segIdx + 1] + seg[2 * segIdx + 2];
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildTree(0, n - 1, 0);

    while (q--) {
        ll a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            b--, c--;
            update(b, c, d, 0, n - 1, 0);
        }
        else {
            cin >> b;
            ans = 0;
            pointQuery(b - 1, 0, n - 1, 0);
            cout << ans << endl;
        }
    }
    return 0;
}
