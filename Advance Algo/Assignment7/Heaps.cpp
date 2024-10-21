#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

public:
    // Constructor
    MaxHeap() {}

    // Inserts a value into the max-heap.
    void insert(int value)
    {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0 && heap[index] > heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Display
    void display()
    {
        for (auto ele : heap)
        {
            cout << ele << " ";
        }
    }
};

vector<int> process(string s)
{
    vector<int> ans;
    // cout << "Processing" << endl;
    for (int i = 0; i < s.length();)
    {
        string curr = "";
        while (i < s.length())
        {
            if (s[i] == ',' || s[i] == '.')
            {
                i += 2;
                ans.push_back(stoi(curr));
                break;
            }
            curr += s[i];
            i++;
        }
        // cout << i << " " << s.length() << endl;
    }

    return ans;
}

int main()
{

    string s;
    getline(cin, s);

    vector<int> A = process(s);
    MaxHeap H = MaxHeap();
    for (int ele : A)
    {
        H.insert(ele);
    }

    H.display();
    cout << endl;

    string t;
    getline(cin, t);

    vector<int> B = process(t);

    for (auto ele : B)
    {
        H.insert(ele);
    }

    H.display();
    return 0;
}