#include<bits/stdc++.h>
using namespace std;
class DSU {
    int n;
    vector<int> parent, rank;
public:
    DSU(int sz) {
        this->n = sz;
        parent.resize(n);
        rank.resize(n);

        for (int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int getParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    void Union(int a, int b) {
        int ulpa = getParent(a);
        int ulpb = getParent(b);

        if (rank[ulpa] == rank[ulpb]) {
            parent[ulpa] = ulpb;
            rank[ulpb]++;
        }
        else if (rank[ulpa] < rank[ulpb]) {
            parent[ulpa] = ulpb;
        }
        else {
            parent[ulpb] = ulpa;
        }
    }

    bool check() {
        int parentMain = parent[0];
        for (int i = 1;i < n;i++) {
            if (parent[i] != parentMain) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.getParent(u) != dsu.getParent(v)) {
                dsu.Union(u, v);
            }
            else {
                return false;
            }
        }

        return dsu.check();
    }
};













