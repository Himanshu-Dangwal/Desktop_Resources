#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &cake,int n,int m,int &k,int i,int j){
    k++;
    cake[i][j]='0';
    
    if(i+1<n && cake[i+1][j]==1)      //Down::
        dfs(cake,n,m,k,i+1,j);
    if(i-1>=0 && cake[i-1][j]==1)	  //Up
        dfs(cake,n,m,k,i-1,j);
    if(j+1<m && cake[i][j+1]==1)	  //Right
        dfs(cake,n,m,k,i,j+1);
    if(j-1>=0 && cake[i][j-1]==1)	  //Left
        dfs(cake,n,m,k,i,j-1);
    if(i-1>=0 && j+1<m && cake[i-1][j+1]==1)
		dfs(cake,n,m,k,i-1,j+1);    
	if(i+1<n && j+1<m && cake[i+1][j+1]==1)
		dfs(cake,n,m,k,i+1,j+1);
	if(i+1<n && j-1>=0 && cake[i+1][j-1]==1)
		dfs(cake,n,m,k,i+1,j-1);
    if(i-1>=0 && j-1>=0 && cake[i-1][j-1]==1)
		dfs(cake,n,m,k,i-1,j-1);
    
}

int getBiggestPieceSize(vector<vector<int>> &cake,int n,int m)
{
	// Write your code here .
    int ans=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(cake[i][j]==1){
                // cout<<"Inside";
                int k=0;
                dfs(cake,n,m,k,i,j);
                ans=max(ans,k);
            }
        }
    }
    return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> cake(n,vector<int>(m));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>cake[i][j];
		}
	}
	
	cout<<getBiggestPieceSize(cake,n,m);
}
