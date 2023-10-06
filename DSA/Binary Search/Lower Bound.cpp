#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	
	int arr[7] = {1,2,2,2,4,4,6};
	
	int idx = upper_bound(arr,arr+7,2) - arr;
	
	cout<<idx<<endl; 
	
	int Loweridx = lower_bound(arr,arr+7,2) - arr;
	cout<<Loweridx<<endl;

	return 0;
}

