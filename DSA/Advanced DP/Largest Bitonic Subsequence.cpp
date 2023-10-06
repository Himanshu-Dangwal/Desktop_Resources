//Longest Bitonic Subsequence::
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
	
	int lis[n];
	lis[0] = 1;
	
	for(int i=1;i<n;i++){
		lis[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[j] <= arr[i]){
				lis[i] = max(lis[i],lis[j] + 1);
			} 
		}
	}
	
	int lds[n];
	lds[n-1] = 1;
	
	for(int i=n-2;i>=0;i--){
		lds[i] = 1;
		for(int j=n-1;j>i;j--){
			if(arr[j] < arr[i]){
				lds[i] = max(lds[i],lds[j] + 1);
			}
		}
	}

	int max_val = INT_MIN;
	
	for(int i=0;i<n;i++){
		max_val = max(max_val,lis[i]+lds[i]-1);
	}
	
	cout<<max_val;
	return 0;
}

