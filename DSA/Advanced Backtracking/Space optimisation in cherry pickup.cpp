#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


int cp(int r1,int c1,int r2,vector<vector<int>>&arr,int ***dp){
	int n = arr.size();
	int c2 = r1 + c1 - r2;
	if(r1 >= n || c1 >= n || r2 >=n || c2 >=n || arr[r1][c1] == -1 || arr[r2][c2] == -1) return INT_MIN;
	int cherries = 0;
	
	
	if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
	
	if(r1 == n-1 && c1 == n-1){
		return arr[r1][c1];
	}
	
	
	if(r1 == r2 && c1 == c2){
		cherries += arr[r1][c1];
	}else{
		cherries += arr[r1][c1] + arr[r2][c2];
	}
	
	//Make 4 calls::
	int f1 = cp(r1,c1+1,r2,arr,dp); //hh
	int f2 = cp(r1,c1+1,r2+1,arr,dp); //hv
	int f3 = cp(r1+1,c1,r2+1,arr,dp); //vv
	int f4 = cp(r1+1,c1,r2,arr,dp); //vh
	
	
	cherries += max(max(f1,f2),max(f3,f4));
	dp[r1][c1][r2] = cherries;
	return cherries;
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
	
	int ***dp = new int**[n];
	for(int i=0;i<n;i++){
		dp[i] = new int*[n];
		for(int j=0;j<n;j++){
			dp[i][j] = new int[n];
			for(int k=0;k<n;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	
	cout<<cp(0,0,0,arr,dp);

	return 0;
}


//vector<vector<vector<int>>> vector_3d(2, vector<vector<int>>(3, vector<int>(4, 1)));

