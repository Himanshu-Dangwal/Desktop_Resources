//When we need to find the lower bound for any sum given:::
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

int query(int sum,int n){
	
	int curr = 0,ans = 0,prevSum=0;
	
	for(int i=log2(n);i>=0;i--){
		if(fen[curr + (1<<i)] + prevSum < sum){
			curr += (1 << i);
			prevSum += fen[curr];
		}
	}
	return curr + 1;
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
	
	int sum;
	cin>>sum;
	
	int lowerBound = query(sum,n);

	return 0;
}

