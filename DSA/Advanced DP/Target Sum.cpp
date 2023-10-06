#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int target;
	cin>>target;
	
	int dp[n+1][target+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=target;j++){
			
			if(i==0 && j==0){
				dp[i][j] = 1;
			}else if(i == 0){
				dp[i][j] = 0;
			}else if(j == 0){
				dp[i][j] = true;
			}else{
				
				dp[i][j] = dp[i-1][j];
				
				if(j >= arr[i-1]){
					dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
				}
				
			}
		}
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=target;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<dp[n][target]<<endl;

	return 0;
}

