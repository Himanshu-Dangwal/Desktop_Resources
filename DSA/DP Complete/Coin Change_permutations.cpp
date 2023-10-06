//Coin Change Permutations::
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
	int dp[target + 1];
	for(int i=0;i<=target;i++){
		dp[i] = 0;
	}
	dp[0]  =1;
	for(int i=1;i<=target;i++){
		for(int j=0;j<n;j++){
			if(i >= arr[j]){
				dp[i] += dp[i-arr[j]] ;
			}
		}
	}
	cout<<dp[target]<<endl;
	return 0;
}

