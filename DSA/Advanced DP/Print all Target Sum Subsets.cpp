#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void printTargetSumSubsets(int arr[],int idx,string ans,int sum,int target,int n){
	
	if(idx == n){
		if(sum == target){
			cout<<ans<<endl;
		}
		return;
	}
	
	printTargetSumSubsets(arr,idx+1,ans + " " +to_string(arr[idx]),sum + arr[idx],target,n);
	printTargetSumSubsets(arr,idx+1,ans,sum,target,n);
	
}

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int target ;
	cin>>target;
	
	string ans = "";
	
	printTargetSumSubsets(arr,0,ans,0,target,n);
	return 0;
}

