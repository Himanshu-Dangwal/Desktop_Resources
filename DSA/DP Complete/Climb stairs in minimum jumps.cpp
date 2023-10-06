//Climb stairs with minimum jumps::
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
	int dp[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = INT_MAX;
	}
	dp[n] = 0;
	for(int i=n-1;i>=0;i--){
		if(arr[i] > 0){
			int minimum = INT_MAX;
			for(int j=1;j<=arr[i];j++){
				if(i+j <= n && dp[i+j]!=INT_MAX){
//					cout<<"inside"<<endl;
					dp[i] = min(minimum,1+dp[i+j]);
				}
			}
		}
	}
//	for(int i=0;i<=n;i++){
//		cout<<dp[i]<<" ";
//	}
	cout<<n<<endl;
	cout<<dp[0]<<endl;
	return 0;
}

