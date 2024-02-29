#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int x, int n)
    {
        n -= 1;
        int answer = 0;
        for (int i = 0; i < 32; ++i)
        {
            int rep = (1 << i);
            cout << rep << endl;
            if ((rep & x) != 0)
            {
                cout << "Here" << endl;
                answer += rep;
            }
            else
            {
                if (n % 2 == 1)
                {
                    answer += rep;
                }
                n /= 2;
            }
        }

        return answer;
    }
};

int main()
{
    Solution solution;
    int x = 42;
    int n = 5;
    int result = solution.solve(x, n);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
