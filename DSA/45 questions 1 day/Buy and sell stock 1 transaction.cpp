//Best time to buy and sell stocks 1 transaction Allowed
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int pist = 0;
	int max_profit = INT_MIN;
	int min_val = INT_MAX;
	
	for(int i=0;i<n;i++){
		if(arr[i] < min_val){
			min_val = arr[i];
		}
		pist = arr[i] - min_val;
		if(pist > max_profit){
			max_profit = pist;
		}
	}
	cout<<max_profit<<endl;
	return 0;
}

