//Count Subarrays with XOR as K::
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
	
	int k;
	cin>>k;
	
	int xoro = 0;
	int count = 0;
	
	unordered_map<int,int> m;
	
	for(int i=0;i<n;i++){
		xoro = xoro ^ arr[i];
		if(m.find(xoro ^ k) != m.end()){
			count += m[xoro^k];
		}
		if(xoro == k){
			count += 1;
		}
		if(m.find(xoro) == m.end()){
			m[xoro] = 1;
		}else{
			m[xoro]++;
		}
	}
	cout<<count<<endl;
	return 0;
}

