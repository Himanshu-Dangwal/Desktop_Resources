#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool check(int arr[],int n,int k,int val){
	int count = 1;
	int sum = 0;
	
	for(int i=0;i<n;i++){
		sum += arr[i];
		
		if(sum > val){
			count++;
			sum = arr[i];
		}
	}
	
	if(count <= k){
		return true;         
	}
 	return false;       
}


int main(){
	int n;
	cin>>n;
	
	int arr[n];
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	
	int k;
	cin>>k;
	
	int maxi = *max_element(arr,arr+n);
//	cout<<maxi;
	int l = maxi;
	int r = sum;
	
	int ans = 0;
	
	while(l <= r){
		ll mid = (l + r)/2;
		if(check(arr,n,k,mid)){
			ans = mid;
			r = mid-1;
		}else{
			l = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

