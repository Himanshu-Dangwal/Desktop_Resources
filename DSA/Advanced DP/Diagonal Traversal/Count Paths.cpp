#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int countPaths(int n,int* arr){
	
	
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;	
	
	if(arr[n] != -1){
		return arr[n];
	}
	
	arr[n] = countPaths(n-1) + countPaths(n-2) + countPaths(n-3); 
	return arr[n];
}


int main(){
	
	int n;
	cin>>n;
	
	int* arr = new int[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = -1;
	}
	
	cout<<countPaths(n,arr);
	
	return 0;
}

