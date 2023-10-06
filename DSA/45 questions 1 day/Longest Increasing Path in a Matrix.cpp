//Longest Increasing Path in a Matrix::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int dfs(int x,int y,vector<vector<int>> &matrix,int n,int m,vector<vector<int>> &dp){
	if(dp[x][y]){
		return dp[x][y];
	}
	
	int dirX[4] = {0,1,0,-1};
	int dirY[4] = {1,0,-1,0};
	int ans = 1;
	for(int i=0;i<4;i++){
		int nX = x + dirX[i];
		int nY = y + dirY[i];
		
		if(nX < 0 || nY < 0 || nX >= n || nY >= m){
			continue;
		}
		if(matrix[x][y] >= matrix[nX][nY]){
			continue;
		}
		ans = max(ans,1 + dfs(nX,nY,matrix,n,m,dp));
	}
	
	return dp[x][y] = ans;
}


int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> matrix;
	
	for(int i=0;i<n;i++){
		vector<int> a;
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		matrix.push_back(a);
	}
	vector<vector<int>> dp(n,vector<int>(m,0));
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans = max(ans,dfs(i,j,matrix,n,m,dp));
		}
	}
	
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<ans<<endl;
	return 0;
}

