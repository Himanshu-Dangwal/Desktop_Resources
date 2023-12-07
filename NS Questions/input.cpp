#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    vector<int> b;
    while (getline(cin, line))
    {
        istringstream iss(line);

        int n;
        while (iss >> n)
            b.push_back(n);
    }
    return 0;
}