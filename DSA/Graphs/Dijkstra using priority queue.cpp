
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>

int main(){
    
    int t;
    cin>>t;
    while(t--){
         
        int v,e;
        cin>>v>>e;

        vector<vector<PII>> adj(v);
		for(int i=0;i<e;i++){
            
            int x,y,w;
            cin>>x>>y>>w;
            adj[x].push_back(make_pair(y,w));
            adj[y].push_back(make_pair(x,w));
            
        }
        
        
        bool visited[v];
        for(int i=0;i<v;i++){
            visited[i] = false;
        }
        
        int distance[v];
        for(int i=0;i<v;i++)
            distance[i] = INT_MAX;
        
        distance[0] = 0;
        
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        // pq - > distance vs vertexNumber
        pq.push(make_pair(0,0));
        
        while(!pq.empty()){
            // cout<<"Inside"<<endl;
			            
            auto curr = pq.top();
            pq.pop();
            visited[curr.second] = true;
            for(auto x : adj[curr.second]){       
                if(distance[x.first] > distance[curr.second] + x.second && !visited[x.first]){
                    distance[x.first] =  distance[curr.second] + x.second;
                    pq.push(make_pair(distance[x.first],x.first));
                }
            }
        }
        for(int i=0;i<v;i++){
            cout<<i<<" "<<distance[i]<<endl;
        }   
    }
}
