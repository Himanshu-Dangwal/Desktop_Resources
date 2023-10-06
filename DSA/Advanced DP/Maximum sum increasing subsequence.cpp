//Maximum Sum Increasing Subsequence::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int dp[n];
	
	dp[0] = arr[0];
	
	int maximum_sum = arr[0];
	
	for(int i=1;i<n;i++){
		int max_val = 0;
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i]){
				max_val = max(max_val,dp[j]);
			}
		}
		dp[i] = max_val;
		dp[i] += arr[i];
		maximum_sum = max(maximum_sum,dp[i]);
	}
	
	cout<<maximum_sum<<endl;
	
	return 0;
}

