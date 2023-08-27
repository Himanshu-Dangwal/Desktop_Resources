void printBFS(int **g,int v,int sv,bool *visited,vector<int> &p){
	queue<int> q;
	q.push(sv);
    p.push_back(sv);
	visited[sv] = true;
	while(!q.empty()){
		int currentVal = q.front();
		q.pop();
		// cout<<currentVal<<endl;
		for(int i=0;i<v;i++){
			if(!visited[i] && g[currentVal][i]==1){
                p.push_back(i);
				q.push(i);
				visited[i] = true;
			}
		}
	}
    return;
}

void bfs(int **g,int v,vector<vector<int>> &find){ 
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> p;
            printBFS(g,v,i,visited,p);
            sort(p.begin(),p.end());
            find.push_back(p);
        }
    }
    delete [] visited;
    return;
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **g = new int*[v];
    for(int i=0;i<v;i++){
        g[i] = new int[v];
        for(int j=0;j<v;j++){
            g[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    vector<vector<int>> find;
    bfs(g,v,find);
    for(int i=0;i<find.size();i++){
        for(int j=0;j<find[i].size();j++){
            cout<<find[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
