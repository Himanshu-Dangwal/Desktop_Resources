using ll = unsigned long long;
ll power(ll x, int y, int p){
    ll res = 1;
    x = x % p; 
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}
 

ll modInverse(ll n, int p){
    return power(n, p - 2, p);
}
 

ll nCrModPFermat(ll n, int r, int p){
    if (n < r) return 0;
    if (r == 0) return 1;
 
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    ll res = (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    return res;
}

class Solution {
public:
    int mod = 1e9 + 7, N = 0;
    int numOfWays(vector<int>& nums) {
        N = max(N, (int)nums.size());
        ll ans = 0;
        
        if(nums.empty() || nums.size() == 1) ans = 1;
        else {
            vector<int> sm, lg;
            for(int i : nums) {
                if(i < nums[0]) sm.push_back(i);
                else if(i > nums[0]) lg.push_back(i);
            }

            int x = sm.size(), y = lg.size();
            int n = x + y;
            ans = (ll)nCrModPFermat(n, x, mod) * (((ll)numOfWays(sm) * numOfWays(lg)) % mod);
        }
        
        if(N == nums.size()) return ((ans - 1) % mod);
        return (ans % mod);
    }
};
