//Highway Billboard Approach 2:::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int m;
	cin>>m;
	
	int n;
	cin>>n;
	unordered_set<int> s;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
	}
	int values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]] = values[i];
	}
	
	int dis;
	cin>>dis;
	
	int dp[m+1];
	dp[0] = 0;
	for(int i=1;i<=m;i++){
		if(s.find(i) != s.end()){
			//Found::
			dp[i] = dp[i-1];
			if(i-dis-1 >= 0){
				dp[i] = max(dp[i],dp[i-dis-1]+values[mp[i]]);
			}
		}else{
			//Not Found::
			dp[i] = dp[i-1];
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}

