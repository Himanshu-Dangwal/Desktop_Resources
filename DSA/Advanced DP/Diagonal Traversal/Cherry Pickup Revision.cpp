#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int maxCC = 0;


int helper(int row,int col,vector<vector<int>>&arr,ccsf){
	
	if(row < 0 || col < 0 || arr[row][col] == -1) return;
	
	if(row == 0 && col == 0){
		maxCC = max(maxCC,ccsf);
		return;
	}
	
	int cherries = arr[row][col];
	arr[row][col] = 0;
	helper(row-1,col,arr,ccsf+cherries);
	helper(row,col-1,arr,ccsf+cherries);
	arr[row][col] = cherries;
	
}

void cp(int row,int col,vector<vector<int>>&arr,int ccsf){
	
	if(row >= arr.size() || col >= arr[0].size() || arr[row][col] == -1){
		return;
	}
	
	if(row == arr.size()-1 && col == arr[0].size()-1){
		helper(arr.size()-1,arr[0].size()-1,arr,ccsf);
	}
	
	int cherries = arr[row][col];
	arr[row][col] = 0;
	cp(row+1,col,arr,ccsf+cherries);
	cp(row,col+1,arr,ccsf+cherries);
	arr[row][col] = cherries;
	
}

int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> arr(n,vector<int>(m));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	cp(0,0,arr,0);
	cout<<maxCC;

	return 0;
}

