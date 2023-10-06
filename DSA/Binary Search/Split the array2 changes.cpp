#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int check(int arr[],int n,int k,int val){
	int count = 1;
	int sum = 0;
	
	cout<<val<<endl;
	
	for(int i=0;i<n;i++){
		sum += arr[i];
		
		if(sum > val){
			count++;
			sum = arr[i];
		}
	}
	cout<<count<<endl;
	if(count < k){
		return 0;         //Decrease end = mid - 1;
	}
	if(count == k){
		return 1;         //Possible answer ,,,end = mid - 1
	}
 	return 2;        //start = mid + 1
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
		
		int get = check(arr,n,k,mid);
		if(get == 0){
			r = mid-1;
		}else if(get == 1){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
		cout<<endl;
		cout<<l<<" "<<r<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

