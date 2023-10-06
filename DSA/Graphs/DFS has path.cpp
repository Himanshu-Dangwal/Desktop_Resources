
#include<bits/stdc++.h>
using namespace std;

bool DFS(int** edges,int v,int sv,int ev,bool *visited){
    visited[sv] = true;
    for(int i=0;i<v;i++){
        if(!visited[i] && edges[sv][i]){
            if(i == ev){
                return true;
            }
            if(DFS(edges,v,i,ev,visited)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        int** edges = new int*[v];
        for(int i=0;i<v;i++){
            edges[i] = new int[v];
            for(int j=0;j<v;j++){
                edges[i][j] = 0;
            }
        }
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            edges[a][b] = 1;
            edges[b][a] = 1;
        }
        int sv,ev;
        cin>>sv>>ev;
        bool* visited = new bool[v];
        for(int i=0;i<v;i++){
            visited[i] = false;
        }
        if(sv==ev){
            cout<<"true"<<endl;
            continue;
        }
        if(DFS(edges,v,sv,ev,visited)){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}
