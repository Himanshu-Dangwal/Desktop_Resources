#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


int maxi_sum_of_m_subarrays(vector<int>&arr,int idx,int m,int k,vector<int>&prefix,vector<vector<int>>&dp){
	
	
	if(idx >= arr.size()){
		return 0;
	}
	
	if(m == 0){
		return 0;
	}
	
	if(dp[idx][m] != -1){
		return dp[idx][m];
	}
	
	int exclude = maxi_sum_of_m_subarrays(arr,idx+1,m,k,prefix,dp);
	int include = prefix[idx] + maxi_sum_of_m_subarrays(arr,idx+k,m-1,k,prefix,dp);
	int ans = max(include,exclude);
	dp[idx][m] =  ans;
	
	return ans;
}


int main(){
	int n;
	cin>>n;
	
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int k,m;
	cin>>m>>k;
	
	
	//to find the maximum sum of m non overlapping subarrays each of size k each::
	vector<int> prefix(n,0);
	int sum = 0;
	for(int i=0;i<k;i++){
		sum += arr[i];
	}
	prefix[0] = sum;
	int idx = 1;
	for(int i=k;i<n;i++){
		sum = sum + arr[i] - arr[i-k];
		prefix[idx] = sum;
		idx++; 
	}
	
	vector<vector<int>> dp(arr.size()+1,vector<int>(m+1,-1));
	
	cout<<maxi_sum_of_m_subarrays(arr,0,m,k,prefix,dp);

	return 0;
}

