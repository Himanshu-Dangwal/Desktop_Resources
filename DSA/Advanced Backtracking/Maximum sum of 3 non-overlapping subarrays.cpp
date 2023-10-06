#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int maxi_sum(vector<int>&arr,int k){
	int n = arr.size();
	int* dp1 = new int[n];
	int* dp2 = new int[n];
	
	int sum = 0;
	for(int i=0;i<n;i++){
		if(i < k){
			sum += arr[i];
			dp1[i] = sum;
		}else{
			sum = sum + arr[i] - arr[i-k];
			dp1[i] = max(dp1[i-1],sum);
		}
	}
	sum = 0;
	for(int i=n-1;i>=0;i--){
		if(i+k >= n){
			sum += arr[i];
			dp2[i] = sum;
		}else{
			sum = sum + arr[i] - arr[i+k];
			dp2[i] = max(dp2[i+1],sum);
		}
	}
	
	int kSizeSum[n];
	sum = 0;
	for(int i=0;i<n;i++){
		if(i < k){
			sum += arr[i];
			kSizeSum[i] = sum;
		}else{
			sum = sum + arr[i] - arr[i-k];
			kSizeSum[i] = sum;
		}
	}
	
	//ksize required = kSizeSum[i+k-1] ...
	int ans = 0;
	int masp = -1; //middle array starting point::
	for(int i=k;i+k+k <= n;i++){
		if(dp1[i-1]+kSizeSum[i+k-1]+dp2[i+k] > ans){
			ans = dp1[i-1]+kSizeSum[i+k-1]+dp2[i+k];
			masp = i;
		}
	}
	int rightIdx = -1;
	int leftIdx = -1;
	int lValue = dp1[masp-1];
	int rValue = dp2[masp+k];
	
	
	//Check in dp1 where there is first occurence of lValue::
	
	for(int i=0;i<masp;i++){
		if(kSizeSum[i+k-1] == lValue){
			leftIdx = i;
			break;
		}
	}
	
	
	//Check in dp2 where there is first occurence of rValue::
	for(int i=masp+k;i<n;i++){
		if(kSizeSum[i+k-1] == rValue){
			rightIdx = i;
			break;
		}
	}
	
	cout<<leftIdx<<" "<<masp<<" "<<rightIdx<<endl;
	return ans;
}


int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	
	cout<<maxi_sum(arr,k);
	return 0;

	return 0;
}

