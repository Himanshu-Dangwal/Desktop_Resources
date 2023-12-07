#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

string findPrimeSum(int start, int end, int targetSum)
{
    try
    {
        if (start < 2 || end < start || targetSum < 0)
        {
            throw string("Invalid input values.");
        }

        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            if (isPrime(i))
            {
                sum += i;
            }
        }

        if (sum < targetSum)
        {
            throw string("Sum is less.");
        }
        else if (sum > targetSum)
        {
            throw string("Sum is high.");
        }
        else
        {
            throw string("Sum is perfect.");
        }
    }
    catch (string err)
    {
        return err;
    }
}

int main()
{
    int start, end, targetSum;
    cin >> start >> end >> targetSum;
    cout << findPrimeSum(start, end, targetSum);
    return 0;
}
