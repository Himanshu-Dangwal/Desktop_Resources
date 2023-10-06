#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000

void floydWarshalls(int** graph,int n,int m){

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k]!=MAX && graph[k][j]!=MAX && graph[i][j] > graph[i][k]+graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

}

int main(){
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int** graph = new int*[n];
        for(int i=0;i<n;i++){
            graph[i] = new int[n];
            for(int j=0;j<n;j++){
                if(i==j){
                    graph[i][j] = 0;
                }else
                	graph[i][j] = MAX;
            }
        }
        for(int i=0;i<m;i++){
            int a,b,w;
            cin>>a>>b>>w;
            a--;
            b--;
			//To handle Mutiple Edges:::
            if(graph[a][b] == MAX){
                graph[a][b] = w;
            	graph[b][a] = w;
            }else{
                if(graph[a][b] > w){
                    graph[a][b] = w;
                    graph[b][a] = w;
                }
            }
        }
        floydWarshalls(graph,n,m);
        int q;
        cin>>q;
        while(q--){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            cout<<graph[a][b]<<endl;
        }
    }
    return 0;
}
