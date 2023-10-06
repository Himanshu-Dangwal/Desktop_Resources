//Unbounded Knapsack::
//It uses 1D dp array as there can be use of an item any number of times until the bag capacity is not violated::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int wts[n];
	for(int i=0;i<n;i++){
		cin>>wts[i];
	}
	int vals[n];
	for(int i=0;i<n;i++){
		cin>>vals[i];
	}
	int mcob;    //Maximum Capacity Of Bag::
	cin>>mcob;
	
	int dp[mcob+1];
	dp[0] = 0;
	
	for(int i=1;i<=mcob;i++){
		int max_val = INT_MIN;
		for(int j=0;j<n;j++){
			if(wts[j] <= i){
				int val = vals[j] + dp[i - wts[j]];
				if(val > max_val){
					max_val = val;
				}
			}
		}
		dp[i] = max_val;
	}
	cout<<dp[mcob]<<endl;
	return 0;
}

