#include <bits/stdc++.h>
using namespace std;

string findGoodNumber(int n, int low, int high)
{
    try
    {
        int cnt = 0;
        for (int i = 2; i * i <= n; i++)
        {
            bool flag = false;
            while (n % i == 0)
            {
                flag = true;
                n /= i;
            }

            if (flag)
            {
                cnt++;
            }
        }

        if (n != 1)
        {
            cnt++;
        }

        if (cnt < low)
        {
            throw string("Count is less");
        }
        if (cnt > high)
        {
            throw string("Count is high");
        }

        return "Count is perfect";
    }
    catch (string err)
    {
        return err;
    }
}

int main()
{
    int n, low, high;
    cin >> n >> low >> high;
    cout << findGoodNumber(n, low, high);
}