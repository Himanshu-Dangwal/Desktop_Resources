#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int K1, K2;
    cin >> K1 >> K2;

    string message;
    getline(cin >> ws, message);

    for (char c : message)
    {
        int asciiValue = static_cast<int>(c);
        int gcdValue = gcd(asciiValue, K1);
        int encryptedValue = gcdValue % K2;

        cout << encryptedValue << " ";
    }

    return 0;
}
