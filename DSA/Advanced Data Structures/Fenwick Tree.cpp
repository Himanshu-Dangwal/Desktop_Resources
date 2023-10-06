//Fenwick Tree to find sum over a range::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int fen[10000];


void update(int idx,int val,n){
	
	while(idx <= n){
		fen[idx] += val;
		idx += idx & (-idx);
	}
}

int query(int idx){
	int ans = 0;
	while(idx > 0){
		ans += fen[idx];
		idx -= idx & (-idx);
	}
	
	return ans;
}


int main(){
	int n;
	cin>>n;
	
	int arr[n];
	int idx = 1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		update(idx,arr[i],n+1);
		idx++;
	}
	
	int q;
	while(q--){
		int l,r;
		cin>>l>>r;
		
		int ans = query(r) - query(l-1);
		cout<<ans<<endl;
	}

	return 0;
}

