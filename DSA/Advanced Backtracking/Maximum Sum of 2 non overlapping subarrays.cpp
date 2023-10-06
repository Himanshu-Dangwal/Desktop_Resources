#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


int maxi_sum(vector<int>&arr,int x,int y){
	int n = arr.size();
	int* dp1 = new int[n];
	int* dp2 = new int[n];
	
	int sum = 0;
	for(int i=0;i<n;i++){
		if(i < x){
			sum += arr[i];
			dp1[i] = sum;
		}else{
			sum = sum + arr[i] - arr[i-x];
			dp1[i] = max(dp1[i-1],sum);
		}
	}
	
	

	
	sum = 0;
	for(int i=n-1;i>=0;i--){
		if(i+y >= n){
			sum += arr[i];
			dp2[i] = sum;
		}else{
			sum = sum + arr[i] - arr[i+y];
			dp2[i] = max(dp2[i+1],sum);
		}
	}
	

	
	
	int ans = 0;
	for(int i=x-1;i<n-y;i++){
		ans = max(ans,dp1[i]+dp2[i+1]);
	}
	//Reversing above::
	
	dp1 = new int[n];
	dp2 = new int[n];
	
	sum = 0;
	for(int i=0;i<n;i++){
		if(i < y){
			sum += arr[i];
			dp1[i] = sum;
		}else{
			sum = sum + arr[i] - arr[i-y];
			dp1[i] = max(dp1[i-1],sum);
		}
	}
	sum = 0;
	for(int i=n-1;i>=0;i--){
		if(i+x >= n){
			sum += arr[i];
			dp2[i] = sum;
		}else{
			sum = sum + arr[i] - arr[i+x];
			dp2[i] = max(dp2[i+1],sum);
		}
	}
	
	for(int i=y-1;i<n-x;i++){
		ans = max(ans,dp1[i]+dp2[i+1]);
	}
	
	return ans;
	
}


int main(){
	int n;
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x,y;
	cin>>x>>y;
	
	//Given an array and 2 sizes as (x and y) ..We need to find 2 non overlapping subarrays of size x and y in arr which have the maximum sum::
	
	cout<<maxi_sum(arr,x,y);

	return 0;
}

