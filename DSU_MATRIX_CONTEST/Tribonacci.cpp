#include <iostream>
#include <vector>

using namespace std;

vector<int> tribonacci()
{
    vector<int> signature;
    int n;

    for (int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        signature.push_back(num);
    }

    cin >> n;
    vector<int> ans;
    if (n == 0)
    {
        return ans;
    }

    if (n == 1)
    {
        ans.push_back(signature[0]);
        return ans;
    }

    if (n == 2)
    {
        ans.push_back(signature[0]);
        ans.push_back(signature[1]);
        return ans;
    }

    if (n == 3)
    {
        return signature;
    }
    int i = 3;
    while (i < n)
    {
        int next_num = signature[i - 1] + signature[i - 2] + signature[i - 3];
        signature.push_back(next_num);
        i++;
    }
    return signature;
}

int main()
{
    vector<int> result = tribonacci();

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
