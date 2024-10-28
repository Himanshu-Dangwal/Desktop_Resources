#include<bits/stdc++.h>

using namespace std;

struct Friend {
    int index;
    int x;
    int y;
};

// Function to calculate distance between two friends
double distance(const Friend& a, const Friend& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int N;
    cin >> N;

    vector<Friend> friends(N);
    for (int i = 0; i < N; i++) {
        friends[i].index = i; // Store the original index
        cin >> friends[i].x >> friends[i].y;
    }

    vector<tuple<double, int, int, int>> groups; // Store stability and indices of groups

    // Iterate over all combinations of three friends
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                double d1 = distance(friends[i], friends[j]);
                double d2 = distance(friends[i], friends[k]);
                double d3 = distance(friends[j], friends[k]);

                // Calculate stability
                double minDistance = min({ d1, d2, d3 });
                double maxDistance = max({ d1, d2, d3 });
                double stability = maxDistance - minDistance;

                // Store the stability and the indices
                groups.emplace_back(stability, friends[i].index, friends[j].index, friends[k].index);
            }
        }
    }

    // Sort groups based on stability in descending order
    sort(groups.rbegin(), groups.rend());

    // To avoid duplicates and ensure that each friend is included only once,
    // we can keep track of used indices.
    vector<bool> used(N, false);
    vector<tuple<int, int, int>> bestGroups; // Best groups to output

    for (const auto& group : groups) {
        int idx1 = get<1>(group);
        int idx2 = get<2>(group);
        int idx3 = get<3>(group);

        // If none of the friends in this group have been used, select this group
        if (!used[idx1] && !used[idx2] && !used[idx3]) {
            bestGroups.emplace_back(idx1, idx2, idx3);
            used[idx1] = true;
            used[idx2] = true;
            used[idx3] = true;
        }
    }

    // Output the groups
    for (const auto& g : bestGroups) {
        cout << get<0>(g) << " " << get<1>(g) << " " << get<2>(g) << endl;
    }

    return 0;
}
