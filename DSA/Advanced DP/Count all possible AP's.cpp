//Count all possible Arithematic progressions of min Length 3 in a given array::
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

	int dp[n];
	dp[0] = dp[1] = 0;
	
	int count = 0;
	
	for(int i=2;i<n;i++){
		if(arr[i]-arr[i-1] == arr[i-1] - arr[i-2]){
			dp[i] = dp[i-1] + 1;
		}else{
			dp[i] = 0;
		}
		
		count += dp[i];
	}
	
	cout<<count<<endl;
	return 0;
}

