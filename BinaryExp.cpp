typedef long long ll;
const int mod = 1e9 + 7;
int binaryExp(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) {
            ans = (ans % mod * a % mod) % mod;
        }
        a = (a % mod * a % mod) % mod;
        b >>= 1;
    }

    return ans;
}

int binaryMul(ll a, ll b) {
    ll ans = 0;
    while (b > 0) {
        if (b & 1) {
            ans = (ans % mod + a % mod) % mod;
        }
        a = (a % mod + a % mod) % mod;
        b >>= 1;
    }

    return ans;
}