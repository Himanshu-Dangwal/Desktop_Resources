#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> powers(100000);
int p = 31;
#define MOD 1000000007
int main()
{
    string pattern, text;
    cin >> text >> pattern;

    // Eg => text = Himanman, pattern = man

    powers[0] = 1;
    for (int i = 1; i < powers.size(); i++)
    {
        powers[i] = (powers[i - 1] * p) % MOD;
    }

    ll hash_pattern = 0;

    for (int i = 0; i < pattern.length(); i++)
    {
        hash_pattern += ((pattern[i] - 'a' + 1) * powers[i]) % MOD;
        cout << hash_pattern << endl;
    }

    cout << hash_pattern << endl;

    vector<int> hash_text(text.length(), 0);
    ll hash_val = 0;
    for (int i = 0; i < text.length(); i++)
    {
        hash_val += ((text[i] - 'a' + 1) * powers[i]) % MOD;
        hash_text[i] = hash_val;
    }
    for (int x : hash_text)
    {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 0; i <= text.length() - pattern.length(); i++)
    {
        ll curr_hash = hash_text[i + pattern.length() - 1];
        if (i - 1 >= 0)
        {
            curr_hash -= hash_text[i - 1];
        }

        if (curr_hash < 0)
            (curr_hash += MOD);
        curr_hash = curr_hash % MOD;

        cout << "Curr Hash = "
             << curr_hash << endl;
        ll to_cmp_with = (powers[i] * hash_pattern) % MOD;
        cout << "To Compare with = " << to_cmp_with << endl;
        if (curr_hash == to_cmp_with)
        {
            cout << i << endl;
        }
    }

    return 0;
}