#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5+5;

int src[N], dst[N], val[N], idx[N];
int ans[N], visited[N], depth[N];
int parent[N], r[N];

vector<vector<pair<int, int>>> graph(N);


// initialize the rank of all elements 0 and make each node as it's parent
void make_set() {
    for(int i = 0 ; i < N ; ++i) {
        r[i] = 0;
        parent[i] = i;
    }
}

// This function is to get parent or set with path compression
int get_parent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = get_parent(parent[x]);
}

// This merging two sets.
// When we merge two sets we clear the previous graph as it's a new set now
void union_set(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    graph[x].clear();
    graph[y].clear();
    visited[x] = visited[y] = false;
    
    // marking parent using rank
    if(x != y) {
        if(r[x] == r[y]) ++r[x];
        if(r[x] < r[y]) swap(x, y);
        parent[y] = x;
    }
}

// To understand the forward and backward edge refer CodeNCode bridges video.
// We are using kruskal to find if the edges are bridge or not.
void kruskal(int v, int index, int h) {
    visited[v] = true;
    depth[v] = h;
    
    for(pair<int, int> p : graph[v]) {
        // forward edge
        if(!visited[p.first]) {
            kruskal(p.first, p.second, h+1);
            depth[v] = min(depth[v], depth[p.first]);
        }
        // backward edge
        else if(p.second != index) {
            depth[v] = min(depth[v], depth[p.first]);
        }
    }
    // if it's not a bridge, then this edge will come in all MST's.
    if(depth[v] == h) ans[index] = 2;
}

int main()
{
	//code
    int n, m;
    cin >> n >> m;
    
    // TAking input
    for(int i = 1 ; i <= m ; i++) {
        cin >> src[i] >> dst[i] >> val[i];
        idx[i] = i;
    }
    
    // Sort edges on the basis of weight
    sort(idx+1, idx+m+1, [&](int x, int y) {
        return val[x] < val[y];
    });
    
    // calling to initialize
    make_set();
  	
    for(int i = 1 ; i <= m ; ) {
        int j = i;
        // processing the edges collectively having same weight and forming a graph
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            int set1 = get_parent(src[idx[j]]);
            int set2 = get_parent(dst[idx[j]]);
            if(set1 != set2) {
                ans[idx[j]] = 1; // marking initially to tell they will be in "at least one".
                graph[set1].push_back({set2, idx[j]});
                graph[set2].push_back({set1, idx[j]});
            }
        }
        
        // Now the graph we made in previous step
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            int v = get_parent(src[idx[j]]);
            if(!visited[v]) {
                kruskal(v, 0, 0);
            }
        }
        
        // merging two sets
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            union_set(src[idx[j]], dst[idx[j]]);
        }
        
        i = j;
    }
    
    // Printing the corresponding answers.
    for(int i = 1 ; i <= m ; ++i) {
        if(ans[i] == 0) cout << "none" << endl;
        else if(ans[i] == 1) cout << "at least one" << endl;
        else cout << "any" << endl;
    }
	
    return 0;
}

