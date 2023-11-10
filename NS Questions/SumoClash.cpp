#include <bits/stdc++.h>
using namespace std;

vector<int> Sumoclash(vector<int> &asteroids)
{
    stack<int> stack;
    for (int it : asteroids)
    {
        int flag = 1;
        while (!stack.empty() and (stack.top() > 0 and it < 0))
        {
            if (abs(stack.top()) < abs(it))
            {
                stack.pop();
                continue;
            }
            else if (abs(stack.top()) == abs(it))
                stack.pop();
            flag = 0;
            break;
        }
        if (flag)
            stack.push(it);
    }
    vector<int> ans(stack.size());
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        ans[i] = stack.top();
        stack.pop();
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b = Sumoclash(a);
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}