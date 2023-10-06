//Paint Houses 3 colours::

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	
	int dp[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			dp[i][j] = 0;
		}
	}
	
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			if(j==0)
				dp[i][j] = arr[i][j] + min(dp[i-1][1],dp[i-1][2]);
			else if(j==1)
				dp[i][j] = arr[i][j] + min(dp[i-1][0],dp[i-1][2]);
			else
				dp[i][j] = arr[i][j] + min(dp[i-1][0],dp[i-1][1]);		
		}
	}
	
	int ans = min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
	cout<<ans<<endl;
	return 0;
}

