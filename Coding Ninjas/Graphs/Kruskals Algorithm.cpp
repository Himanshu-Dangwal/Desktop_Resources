#include<bits/stdc++.h>
using namespace std;

class Edge{
  public:
    	int src,dest,weight;
};
int getParent(int v,int *parent){
    if(parent[v] == v){
        return v;
    }
    return (parent[v] = getParent(parent[v],parent));    //Path Compression:::
}

bool cmp(Edge a,Edge b){
    return a.weight < b.weight ;
}
Edge* kruskals(Edge *edges,int n,int e){
    sort(edges,edges+e,cmp);
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    Edge *output = new Edge[n-1];
    int count = 0;
    int i=0;
    while(count < n-1){ 
        Edge currentEdge = edges[i];
        int srcP = getParent(currentEdge.src,parent); 
        int destP = getParent(currentEdge.dest,parent);
    	if(srcP != destP){
            output[count] = currentEdge;
            count+=1;
            parent[srcP] = destP;
        }
        i+=1;
    }
    return output;
}

int main(){
    int v,e;
    cin>>v>>e;
    Edge *edges = new Edge[e];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i].src = a;
        edges[i].dest = b;
        edges[i].weight = c;
    }
    Edge *output = kruskals(edges,v,e);
    for(int i=0;i<v-1;i++){
        if(output[i].src < output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }else{
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
    }
    return 0;
}

