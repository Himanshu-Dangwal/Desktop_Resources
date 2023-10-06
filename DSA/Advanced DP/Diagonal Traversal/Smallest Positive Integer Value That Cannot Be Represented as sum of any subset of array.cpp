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
	sort(arr,arr+n);
	int res = 1;
	for(int i=0;i<n && arr[i] <= res;i++){
		res += arr[i];
	}
	
	cout<<res<<endl;

	return 0;
}

