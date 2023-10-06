//Allotment of books::

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool check(int arr[],int val,int k,int n,int* count){
	*count = 1;
	int sum = 0;
	for(int i=0;i<n;i++){
		
		if(arr[i] > val)
			return false;
		
		sum += arr[i];
		if(sum > val){
			*count++;
			sum = arr[i];
		}
	}
	if(*count <= k){
		return true;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	int low = INT_MAX;
	int high = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		low = min(low,arr[i]);
		high += arr[i];
	}
	
	
	int k;
	cin>>k;
	
	int res = -1;
	while(low <= high){
		int mid = (low + high) >> 1;
		int count = 0;
		if(check(arr,mid,k,n,&count)){
			if(count == k)
				res = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	
	if(res != -1){
		cout<<res<<endl;
	}else{
		cout<<"Not Possible"<<endl;
	}
	

	return 0;
}

