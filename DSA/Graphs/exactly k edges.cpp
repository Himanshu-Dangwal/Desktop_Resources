// Dynamic Programming based C++ program to find shortest path with
// exactly k edges
#include <iostream>
#include <climits>
using namespace std;


#define V 4
#define INF INT_MAX

int shortestPath(int **graph,int vertices, int u, int v, int k)
{

	int sp[vertices][vertices][k+1];

	for (int e = 0; e <= k; e++)
	{
		for (int i = 0; i < vertices; i++) 
		{
			for (int j = 0; j < vertices; j++) 
			{
				
				sp[i][j][e] = INF;

			
				if (e == 0 && i == j)
					sp[i][j][e] = 0;
				if (e == 1 && graph[i][j] != INF)
					sp[i][j][e] = graph[i][j];

			
				if (e > 1)
				{
					for (int a = 0; a < vertices; a++)
					{
						if (graph[i][a] != INF && i != a && j!= a && sp[a][j][e-1] != INF)
							sp[i][j][e] = min(sp[i][j][e], graph[i][a] + sp[a][j][e-1]);
					}
				}
			}
		}
	}
	return sp[u][v][k];
}


int main()
{
	int u,v;
	cin>>u>>v;
	int **graph = new int*[u];
	for(int i=0;i<u;i++){
		graph[i] = new int[u];
		for(int j=0;j<u;j++){
			graph[i][j] = INT_MAX;
			if(i == j){
				graph[i][j] = 0;
			}
		}
	}
	
	for(int i=0;i<v;i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a][b] = c;
	}
	int x,y,k;
	cin>>x>>y>>k;
	cout << shortestPath(graph,u, x, y, k);
	return 0;
}

