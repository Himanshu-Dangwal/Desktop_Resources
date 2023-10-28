#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    stack<int> st;

    void push(int x)
    {
        st.push(x);
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    void top()
    {
        if (st.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << st.top() << endl;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    Stack s;

    while (t-- > 0)
    {
        string str;
        cin >> str;

        if (str == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (str == "pop")
        {
            s.pop();
        }
        else if (str == "top")
        {
            s.top();
        }
    }

    return 0;
}
