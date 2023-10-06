//Given an N*M matrix of 0's and 1's ..Count all possible paths from top left to bottom right::

/*
	1 represents that the particular position is blocked::
	0 represents that the particular position is not blocked and we can go though it
	There are only 2 possible ways to travel::
		First GO towards Bottom
		Second Go Towards Right
		The goal is to reach the bottom right of the matrix::
*/		
		
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	int dp[n][m];
	
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1 || j==m-1){
				if(arr[i][j] == 0){
					dp[i][j] = 1;
				}else{
					dp[i][j] = 0;
				}
			}
			else{
				if(arr[i][j] == 1){
					dp[i][j] = 0;
				}else{
					dp[i][j] = dp[i][j+1] + dp[i+1][j];
				}
			}
		}
	}
	
	cout<<dp[0][0]<<endl;
	
	return 0;
}

