#include <bits/stdc++.h>
using namespace std;

void solve(string curr, string s, int i, vector<string> &ans)
{
    // if end of the string is reached
    if (i == s.length())
    {
        ans.push_back(curr); // push the current "curr" string to ans
        return;
    }

    if (isdigit(s[i]))
    { // case 1
        curr.push_back(s[i]);
        solve(curr, s, i + 1, ans);
    }
    else
    { // case 2
        // sub case 1, considering lower case
        string c1 = curr;
        c1.push_back(tolower(s[i]));
        solve(c1, s, i + 1, ans);

        // sub case 2, considering upper case
        string c2 = curr;
        c2.push_back(toupper(s[i]));
        solve(c2, s, i + 1, ans);
    }
}

vector<string> generatePermutations2(string S)
{

    vector<string> ans;
    ans.clear();
    solve("", S, 0, ans);
    return ans;
}

void solve2(string curr, string s, int i, vector<string> &ans)
{
    // if end of the string is reached
    if (i == s.length())
    {
        ans.push_back(curr); // push the current "curr" string to ans
        return;
    }

    if (isdigit(s[i]))
    { // case 1
        curr.push_back(s[i]);
        solve(curr, s, i + 1, ans);
    }
    else
    {
        // sub case 2, considering upper case
        string c2 = curr;
        c2.push_back(toupper(s[i]));
        solve(c2, s, i + 1, ans);

        // case 2
        // considering lower case
        string c1 = curr;
        c1.push_back(tolower(s[i]));
        solve(c1, s, i + 1, ans);
    }
}

vector<string> generatePermutations(string S)
{
    vector<string> ans;
    ans.clear();
    solve2("", S, 0, ans);
    return ans;
}

bool check(vector<string> &a, vector<string> &b)
{
    if (a.size() != b.size())
        return false;

    unordered_set<string> st;

    for (auto &s : a)
    {
        st.insert(s);
    }

    for (auto &s : b)
    {
        if (st.find(s) == st.end())
            return false;
    }

    return true;
}

int main()
{
    string str;
    cin >> str;

    vector<string> permutations2 = generatePermutations2(str);
    vector<string> permutations = generatePermutations(str); // Students will implement

    // for (auto &s : permutations2)
    // {
    //     cout << s << " ";
    // }
    // cout << endl;
    // for (auto &s : permutations)
    // {
    //     cout << s << " ";
    // }

    if (check(permutations2, permutations))
    {
        for (auto &s : permutations2)
        {
            cout << s << " ";
        }
    }
}
