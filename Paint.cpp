typedef long long ll;
const int mod = 1e9 + 7;
ll power(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;


    ll x = power(a, n / 2);
    if (n % 2 == 0) return (x % mod * x % mod) % mod;

    return ((a % mod * x % mod) % mod * x % mod) % mod;
}

int countWaysToColorHouses(int n) {
    int k = n / 2;
    return (2 % mod * power(3, k) % mod) % mod;
}