#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;



int main(){
	
	int n;
	cin>>n;
	
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	vector<int> msb(32,0);
	
	for(int i=0;i<n;i++){
		int idx = log2(arr[i]);
		msb[idx]++;
	}
	
	ll total = 0;

	for(int i=0;i<32;i++){
		total += (msb[i]*1LL*(msb[i]-1))/2;
	}
	
	cout<<total;

	return 0;
}


