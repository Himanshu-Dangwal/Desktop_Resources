#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> overlap(n + 1, 0); // To track job overlaps

    // Mark the start and end of each job
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        overlap[l]++; // Job starts at day l
        if (r + 1 <= n)
        {
            overlap[r + 1]--; // Job ends after day r
        }
    }

    // Prefix sum to calculate the actual overlap on each day
    for (int i = 1; i <= n; i++)
    {
        overlap[i] += overlap[i - 1];
    }

    // Use sliding window to calculate the number of jobs in each window of size d
    int current_overlap = 0;

    // Calculate overlap for the first window [1, d]
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i < d; i++)
    {
        pq.push({overlap[i], i});
    }

    int max_overlap = current_overlap, min_overlap = current_overlap;
    int best_start_max = 1, best_start_min = 1;

    // Slide the window from day 2 to (n - d + 1)
    for (int i = 2; i <= n - d + 1; i++)
    {
        // Adjust the current overlap by removing the contribution of the previous window's first day
        // and adding the contribution of the new day added to the window
        pq.push({overlap[i + d - 1], i + d - 1});
        while (pq.top().second < i)
            pq.pop();

        int curr_overlap = pq.top().first;

        // Track maximum overlap and minimum overlap
        if (current_overlap > max_overlap)
        {
            max_overlap = current_overlap;
            best_start_max = i;
        }
        if (current_overlap < min_overlap)
        {
            min_overlap = current_overlap;
            best_start_min = i;
        }
    }

    // Output the results for this test case
    cout << best_start_max << " " << best_start_min << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
