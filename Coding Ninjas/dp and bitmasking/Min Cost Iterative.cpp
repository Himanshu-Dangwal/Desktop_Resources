//Min COst Iterative Solution Dp and Bitmasking::

#include<bits/stdc++.h>
using namespace std;

int minCost(int **cost,int n){
	int dp[1<<n];
	for(int i=0;i<(1<<n);i++){
		dp[i] = INT_MAX;
	}
	for(int mask = 0;mask<((1<<n)-1);mask++){
		int temp = mask;
		//For the number of set bits::set k = 0 initially::
		int k = 0;
		while(temp>0){
			if(temp%2==1){
				k++;
			}
			temp = temp/2;
		}
		for(int j=0;j<n;j++){
			if(!(mask&(1<<j))){
				dp[mask|(1<<j)] = min(dp[mask|(1<<j)],cost[k][j]+dp[mask]);
			}
		}
	}
	return dp[(1<<n)-1];
}

int main(){
	int n;
	cin>>n;
	int **cost = new int*[n];
	for(int i=0;i<n;i++){
		cost[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>cost[i][j];
		}
	}
	cout<<minCost(cost,n)<<endl;
}
