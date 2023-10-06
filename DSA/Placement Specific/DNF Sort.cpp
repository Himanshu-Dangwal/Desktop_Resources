//DNF Sort
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int low = 0;
	int high = n-1;
	int mid = 0;
	
	while(mid <= high){
		if(arr[mid] == 1){
			mid++;
		}else if(arr[mid] == 2){
			swap(arr[mid],arr[high]);
			high--;
		}else{
			swap(arr[mid],arr[low]);
			mid++;
			low++;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	

	return 0;
}

