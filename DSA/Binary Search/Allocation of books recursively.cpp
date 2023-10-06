//Books allocation using recursion
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


int allocateBooks(int arr[],int n,int k,int idx){
	
	if(idx == n && k == 0){
		return 0;
	}
	
	if(idx == n || k <= 0){
		return INT_MIN;
	}
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for(int j=idx;j<n-1;j++){
		maxi = max(maxi,max(arr[j] + allocateBooks(arr,n,k,idx+1) ,arr[j] + allocateBooks(arr,n,k-1,idx+1 ) ));
		mini = min(mini,maxi);
	}
	
	return mini;
}

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	
	cout<<allocateBooks(arr,n,k,0);

	return 0;
}

