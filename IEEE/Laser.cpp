#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int L, N, M;
    cin >> L >> N >> M;

    vector<int> horizontalLines; // For U beams
    vector<int> verticalLines;   // For R and L beams

    // Process beams from laser A
    for (int i = 0; i < N; i++) {
        char direction;
        int coordinate;
        cin >> direction >> coordinate;
        if (direction == 'U') {
            horizontalLines.push_back(coordinate); // Horizontal line
        }
        else if (direction == 'R') {
            verticalLines.push_back(coordinate); // Vertical line
        }
    }
    ll ans = N + 1;
    // cout << ans << endl;
    sort(horizontalLines.begin(), horizontalLines.end());
    sort(verticalLines.begin(), verticalLines.end());
    // for (auto ele : horizontalLines) cout << ele << " ";
    // cout << endl;

    // for (auto ele : verticalLines) cout << ele << " ";
    // cout << endl;
    for (int i = 0; i < M; i++) {
        char direction;
        int coordinate;
        cin >> direction >> coordinate;
        if (direction == 'U') {
            int cnt = upper_bound(horizontalLines.begin(), horizontalLines.end(), coordinate) - horizontalLines.begin();
            // cout << "cnt= " << cnt << endl;
            // cout << horizontalLines[horizontalLines.size() - 1] << endl;
            // cout << coordinate << endl;
            ans += horizontalLines.size() - cnt;
            ans += verticalLines.size();
            ans++;
        }
        else if (direction == 'L') {
            ans += horizontalLines.size() + verticalLines.size() + 1;
        }
        // cout << ans << endl;
    }

    cout << ans;
    return 0;
}
