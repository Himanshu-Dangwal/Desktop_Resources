struct Compare
{
    bool operator()(const string &a, const string &b)
    {
        if (a.length() != b.length())
        {
            return a.length() > b.length();
        }

        return a > b;
    }
};

class Solution
{
public:
    string kthLargestNumber(vector<string> &nums, int k)
    {
        priority_queue<string, vector<string>, Compare> pq;

        for (auto str : nums)
        {
            pq.push(str);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};