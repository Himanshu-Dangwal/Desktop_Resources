//Rotten Oranges question of playlist stack of Take u forward : ) //STRIVER
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }


int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> grid;
	
	for(int i=0;i<n;i++){
		vector<int> a;
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			a.push_back(x);
		}
//		cout<<"Here"<<endl;
		grid.push_back(a);
	}
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<grid[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<orangesRotting(grid)<<endl;
	return 0;
}

