#include<bits/stdc++.h>
using namespace std;

class Edge{
  public:
    int start,end,weight;
};

bool compare(Edge a,Edge b){
    return a.weight < b.weight;
}

int getParent(int a,int* ds){
    if(ds[a] == a)
        return a;
    return ds[a] = getParent(ds[a],ds);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        int *ds = new int[v];
        for(int i=0;i<v;i++){
            ds[i] = i;
        }
        Edge *edges = new Edge[e];
        for(int i=0;i<e;i++){
            int a,b,w;
            cin>>a>>b>>w;
            edges[i].start = a;
            edges[i].end = b;
            edges[i].weight = w;
        }
        sort(edges,edges+e,compare);
        int count = 0;
        int final_weight = 0;
        for(int i=0;i<e;i++){
            if(count == v-1)
                break;
            Edge current = edges[i];
            int start_parent = getParent(current.start,ds);
            int end_parent = getParent(current.end,ds);
            if(start_parent != end_parent){
                final_weight += current.weight;
                ds[start_parent] = end_parent;
            }
        }
        cout<<final_weight<<endl;
    }
    return 0;
}
