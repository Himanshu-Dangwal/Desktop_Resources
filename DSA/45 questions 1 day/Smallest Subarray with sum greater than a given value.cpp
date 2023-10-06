//Smallest Subarray with sum greater than a given value :::
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
	
	int x;
	cin>>x;
	
	
	int curr_sum = 0;
	int min_val = n+1;
	
	int s = 0;
	int e =0;
	
	while(e < n){
		
		while(curr_sum <= x && e < n){
			curr_sum += arr[e++];
		}
		
		while(curr_sum > x && s < n){
			
			if(e-s < min_val){
				min_val = e-s;
			}
			
			curr_sum -= arr[s++];
		}
	}
	cout<<min_val<<endl;
	return 0;
}

