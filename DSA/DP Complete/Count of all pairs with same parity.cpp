//Count of all possible pairs of elemetns having same aprity::
//i.e all pairs in which both elements are either even or odd::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int count_all_pairs(int arr[],int n){
	
	int count = 0;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((arr[i]%2==0 && arr[j]%2==0) || (arr[i]%2 != 0  && arr[j]%2 != 0)){
				count++;
			}
		}
	}
	
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<count_all_pairs(arr,n);
	
	return 0;
}

