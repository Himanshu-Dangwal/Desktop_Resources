#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int maxCC = 0;  // maximum cherries collected
//ccsf = chery collected so far::

void helper(int row,int col,vector<vector<int>>&arr,int ccsf){
	
	if(row < 0 || row >= arr.size() || col < 0 || col >= arr.size() || arr[row][col] == -1){
		return;
	}
	
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
	
	if(row < 0 || row >= arr.size() || col < 0 || col >= arr.size() || arr[row][col] == -1){
		return;
	}
	
	if(row == arr.size()-1 && col == arr.size()-1){
		helper(row,col,arr,ccsf);
	}
	
	int cherries = arr[row][col];
	arr[row][col] = 0;
	cp(row+1,col,arr,ccsf+cherries);
	cp(row,col+1,arr,ccsf+cherries);
	arr[row][col] = cherries;
	
}




int main(){
	int n;
	cin>>n;
	
	vector<vector<int>> arr(n,vector<int>(n));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	cp(0,0,arr,0);
	cout<<maxCC;
	return 0;

	return 0;
}

