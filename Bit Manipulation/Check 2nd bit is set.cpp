// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if ((x & (1 << 2)) == 0)
        {
            cout << "No ";
        }
        else
        {
            cout << "Yes ";
        }
    }
}