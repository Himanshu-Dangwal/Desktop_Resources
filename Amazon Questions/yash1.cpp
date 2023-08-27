#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int d = arr[1]-arr[0];
	bool flag = true;
	for(int i=2;i<n;i++){
		if(arr[i]-arr[i-1] != d){
			flag = false;
			break;
		}
	}
	
	if(flag){
		return (arr[n-1] + d);
	}
	
	int r = arr[1]/arr[0];
	flag = true;
	for(int i=2;i<n;i++){
		if(arr[i]/arr[i-1] != r){
			flag = false;
			break;
		}
	}	
	
	if(flag){
		return arr[n-1]*r;
	}
	
	return arr[n-1]+arr[n-2];

	
}
