//Dp and Bitmasking ...;::
//Minimum cost ...

//Problem Statement::: there are 4 persons and there are 4 types of jobs available .One person can do only one type of job.Find the mincost by assigning each person a particular job:::
#include<bits/stdc++.h>
using namespace std;

int find_Min_Cost(int **cost,int n,int p,int mask,int *dp){
	
	if(p>=n){
		return 0;
	}
	
	if(dp[mask]!= INT_MAX){
		return dp[mask];
	}
	
	int min = INT_MAX;
	for(int j=0;j<n;j++){
		if(!((1<<j)&mask)){
			//if jth bit is not set::
			int ans = find_Min_Cost(cost,n,p+1,(mask|(1<<j)),dp)+cost[p][j];
			if(ans < min)
				min = ans;
		}
	}
	dp[mask] = min;
	return min;
}

int main(){
	int n; //For square matrix::
	cin>>n;
	//Initialize a dp array for memoization::
	int *dp = new int[1<<n]; 
	for(int i=0;i<(1<<n);i++){
		dp[i] = INT_MAX;
	}
	int** cost = new int*[n];
	for(int i=0;i<n;i++){
		cost[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>cost[i][j];
		}
	}
	cout<<find_Min_Cost(cost,4,0,0,dp)<<endl;
	return 0;
}
