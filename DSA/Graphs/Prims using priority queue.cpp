#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int v,e;
        cin>>v>>e;
        
       	int**g = new int*[v];
        for(int i=0;i<v;i++){
            g[i] = new int[v];
            for(int j=0;j<v;j++){
                g[i][j] = INT_MAX;
            }
        }
        
        for(int i=0;i<e;i++){
            int x,y,z;
            cin>>x>>y>>z;
            
            if(g[x][y] == INT_MAX){
                g[x][y] = z;
                g[y][x] = z;
                
            }else{
                if(g[x][y] > z){
                    g[y][x] = z;
                	g[x][y] = z;
                }
            }
        }
        
        int* distance = new int[v];
        for(int i=0;i<v;i++){
            distance[i] = INT_MAX;
        }
        
        distance[0] = 0;
        
        int* parent = new int[v];
        for(int i=0;i<v;i++){
            parent[i] = INT_MIN;;
        }
        
        parent[0] = -1;
        
        int* visited = new int[v];
        for(int i=0;i<v;i++){
            visited[i] = 0;
        }
        
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        pq.push(make_pair(0,0));
        
        //distance vs vertec number::
        long weight = 0;
        while(!pq.empty()){
            auto currentNode = pq.top();
            
            int vertex = currentNode.second;
            pq.pop();
            
            visited[vertex] = 1;
            
            for(int i=0;i<v;i++){
                if(i != vertex && !visited[i] && g[vertex][i] != INT_MAX){
                    if(distance[i] > g[vertex][i]){
                        distance[i] = g[vertex][i];
                        parent[i] = vertex;
                        pq.push(make_pair(distance[i],i));
                    }
                }
            }
        }
        
        for(int i=0;i<v;i++){
            if(distance[i] != INT_MAX){
                weight += distance[i];
            }
        }
        
        cout<<weight<<endl;
    }
}

