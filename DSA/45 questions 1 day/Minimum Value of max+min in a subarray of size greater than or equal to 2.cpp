//Given an array Find the minimum sum of maximum and minimum element of subarray.The size of subarray can be greater than or equal to 2

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
	
	int min_sum = arr[0] + arr[1];
	
	for(int i=1;i+1<n;i++){
		min_sum = min(min_sum,arr[i] + arr[i+1]);
	}
	
	cout<<min_sum<<endl;
	return 0;
}

