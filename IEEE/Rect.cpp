#include <bits/stdc++.h>
using namespace std;

long long maxRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    long long max_area = 0;
    for (int i = 0; i < n; ++i) {
        max_area = max(max_area, (long long)(right[i] - left[i] - 1) * heights[i]);
    }
    return max_area;
}

long long maxModifiedArea(vector<int>& heights, int X) {
    int n = heights.size();
    long long max_area = 0;

    for (int i = 0; i < n; ++i) {
        int original_height = heights[i];
        heights[i] = X;

        max_area = max(max_area, maxRectangleArea(heights));

        heights[i] = original_height;
    }

    return max_area;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> heights(N);

    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    long long max_area_without_mod = maxRectangleArea(heights);

    long long max_area_with_mod = maxModifiedArea(heights, X);

    cout << max(max_area_without_mod, max_area_with_mod) << endl;

    return 0;
}
