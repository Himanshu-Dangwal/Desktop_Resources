//Maximum Sum Non Adjacent Elements Not Exceeding K::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

//int dp[1005][1005];

int max_sum(int arr[],int n,int k,int **dp){
	
	if(n<=0)
		return 0;
	if(dp[n][k] != -1)
		return dp[n][k];	
		
	//Exclude::
	int option1 = max_sum(arr,n-1,k,dp);
	int option2 = INT_MIN;
	if(k >= arr[n-1]){
		option2 = arr[n-1] + max_sum(arr,n-2,k-arr[n-1],dp);
	}
	option1 = max(option1,option2);
	
	dp[n][k] = option1;
	return dp[n][k];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[k+1];
		for(int j=0;j<=k;j++){
			dp[i][j] = -1;
		}
	}
	
	cout<<max_sum(arr,n,k,dp);
	return 0;
}

