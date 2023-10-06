#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000

class Edge{
  	public:
    	int src,dest,weight;
};

int main(){
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int source,destination;
        cin>>source>>destination;
    	Edge** edges = new Edge*[m];
    	for(int i=0;i<m;i++){
        	edges[i] = new Edge();
        	cin>>edges[i]->src>>edges[i]->dest>>edges[i]->weight;
    	}
        
        //Distance Array:::
        int* dist = new int[n+1];
        for(int i=0;i<=n;i++){
            dist[i] = MAX;
        }
        dist[source] = 0;
        
        //Loop n-1 times::
        //Bellman Ford Logic::
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                int u = edges[j]->src;
                int v = edges[j]->dest;
                int weight = edges[j]->weight;
                
                if(dist[u] != MAX  &&  dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight; 
                }
            }
        }
		cout<<dist[destination]<<endl;
    }
    return 0;
}
