//Maximum Subarray size with atleast k elements ::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	
	int kadanes_sum[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int max_sum[n];
	max_sum[0] = arr[0];
	
	int curr = arr[0];
	
	for(int i=1;i<n;i++){
		if(curr_sum > 0){
			curr_sum += arr[i];
		}else{
			curr_sum = arr[i];
		}
		
		max_sum[i] = curr_sum;
	}
	
	int ans = INT_MIN;
	
	int exactK = 0;
	for(int i=0;i<k;i++){
		exactK += arr[i];
	}
	
	if(exactK > ans){
		ans = exactK;
	}
	
	for(int i=k;i<n;i++){
		exactK = exactK + arr[i] - arr[i-k];
		
		if(exactK > ans){
			ans = exactK;
		}
		
		int moreThanK = exactK;
		moreThanK = moreThanK + max_sum[i-k];
		
		if(moreThanK > ans){
			ans = moreThanK;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}








