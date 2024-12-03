#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    int n, m;
    cin >> n >> m;

    indexed_set hotels;
    vector<int> hotel_rooms(n);

    for (int i = 0; i < n; i++) {
        cin >> hotel_rooms[i];
        hotels.insert({ hotel_rooms[i], i });
    }

    vector<int> groups(m);
    for (int i = 0; i < m; i++) {
        cin >> groups[i];
    }

    for (int i = 0; i < m; i++) {
        int needed = groups[i];

        auto it = hotels.lower_bound({ needed, 0 });
        cout << needed << " " << it->first << " " << it->second << endl;

        if (it == hotels.end()) {
            cout << 0 << " ";
        }
        else {
            int hotel_index = it->second;
            cout << hotel_index + 1 << " ";
            cout << endl;

            hotels.erase(it);
            hotel_rooms[hotel_index] -= needed;

            if (hotel_rooms[hotel_index] > 0) {
                cout << "Here" << endl;
                hotels.insert({ hotel_rooms[hotel_index], hotel_index });
            }
        }
    }

    cout << endl;
    return 0;
}
