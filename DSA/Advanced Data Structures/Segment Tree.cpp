//Segmenty Tree Max between L and R::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int seg[10000];

void build(int idx,int arr[],int low,int high){
	
	if(low == high){
		seg[idx] = arr[low];
		return;
	}
	
	int mid = (low + high) >> 1;
	build(2*idx + 1,arr,low,mid);
	build(2*idx + 2,arr,mid+1,high);
	
	seg[idx] = max(seg[2*idx +1],seg[2*idx+2]);
	return;
}


int query(idx,int low,int high,int l,int r){
	
	if(low>=l && high<=r){
		return seg[idx];
	}else if(low<l || high > r){
		return INT_MIN;
	}else{
		int mid = (low + high) >> 1;
		int a = query(2*idx +1,low,mid,l,r);
		int b = query(2*idx+2,mid+1,high,l,r);
		
		return max(a,b);
	}
	
}

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	build(0,arr,0,n-1);
	
	int q;
	cin>>q;
	
	while(q--){
		int l,r;
		cin>>l>>r;
		
		query(0,0,n-1,l,r);	
	}
		

	return 0;
}







