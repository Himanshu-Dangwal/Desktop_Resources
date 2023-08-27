//HighWay BillBoard Question:::
//PProach 1 :: O(n^2) approach:::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int m;    //Total miles of road::
	cin>>m;
	int n;   
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	int dis;
	cin>>dis;
	int dp[n];
	dp[0] = values[0];
	for(int i=1;i<n;i++){
		int max_val = INT_MIN;
		for(int j=i-1;j>=0;j--){
			if((arr[i] - arr[j]) > dis){
				if((dp[j]+values[i]) > max_val){
					max_val = dp[j] + values[i];
				}
			}
		}
		if(max_val > values[i]){
			dp[i] = max_val;
		}else{
			dp[i] = values[i];
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;
}

