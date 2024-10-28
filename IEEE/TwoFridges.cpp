#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    int best_T1 = 101, best_T2 = 101;

    for (int T1 = -100; T1 <= 100; ++T1) {
        for (int T2 = T1; T2 <= 100; ++T2) {
            bool valid = true;

            for (auto& interval : intervals) {
                int a = interval.first, b = interval.second;

                if ((T1 < a || T1 > b) && (T2 < a || T2 > b)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                if (T1 < best_T1 || (T1 == best_T1 && T2 < best_T2)) {
                    best_T1 = T1;
                    best_T2 = T2;
                }
            }
        }
    }


    if (best_T1 == 101) {
        cout << -1 << endl;
    }
    else {
        cout << best_T1 << " " << best_T2 << endl;
    }

    return 0;
}
