#include <bits/stdc++.h>
using namespace std;

vector<int> getLPS(string pattern)
{
    int n = pattern.length();
    vector<int> lps(n);
    lps[0] = 0;
    int j = 0, i = 1;
    while (i < n)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int KMP(string text, string pattern)
{

    vector<int> lps = getLPS(pattern);
    int i = 0, j = 0;

    while (i < text.length() && j < pattern.length())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (j == pattern.length())
    {
        return i - j;
    }

    return -1;
}

int main()
{
    string pattern, text;
    cin >> text >> pattern;

    cout << KMP(text, pattern);
}