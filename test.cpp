#include <bits/stdc++.h>
using namespace std;

class Data
{

public:
    int val;
    string name;
    Data(int v, string s)
    {
        val = v;
        name = s;
    }

    bool operator<(const Data &other) const
    {
        return val < other.val;
    }
};

int main()
{
    // set<pair<string, int>> st;
    // st.insert({"pizza", 2});
    // st.insert({"burger", 3});
    // st.insert({"pizza", 3});

    // for (auto it : st)
    // {
    //     cout << it.first << " " << it.second;
    //     cout << endl;
    // }

    // Default behaviour of priority queue
    priority_queue<Data> pq;
    pq.push(Data(10, "Himanshu"));
    pq.push(Data(30, "Apoorv"));
    pq.push(Data(20, "Vikas"));

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        cout << it.val << " " << it.name << endl;
    }
    return 0;
}