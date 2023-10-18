#include <bits/stdc++.h>
using namespace std;

int *build(string concatenated)
{
    int *z = new int[concatenated.length()];
    z[0] = 0;
    int l = 0;
    int r = 0;

    for (int i = 1; i < concatenated.length(); i++)
    {
        if (i > r)
        {
            l = r = i;
            while (concatenated[r - l] == concatenated[r] && r < concatenated.length())
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] + i <= r)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (concatenated[r - l] == concatenated[r] && r < concatenated.length())
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

bool zAlgo(string text, string pattern)
{

    string concatenated = pattern + '$' + text;

    int l = concatenated.length();
    int *z = new int[l];

    z = build(concatenated);

    for (int i = pattern.length() + 1; i < l; i++)
    {
        if (z[i] == pattern.length())
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string text, pattern;

    cin >> text >> pattern;

    if (zAlgo(text, pattern))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}