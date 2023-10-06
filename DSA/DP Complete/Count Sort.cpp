//Count Sort::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void countSort(int arr[],int n){
	int max_val = INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i] > max_val){
			max_val = arr[i];
		}
	}
	
	int count[max_val+1];
	for(int i=0;i<=max_val;i++){
		count[i] = 0;
	}
	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	//Modifying Count arrray::
	
	for(int i=1;i<=max_val;i++){
		count[i] += count[i-1];
	}
	int output[n];
	
	for(int i=n-1;i>=0;i--){
		output[--count[arr[i]]] = arr[i];
	}
	for(int i=0;i<n;i++){
		arr[i] = output[i];
	}
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
	
	countSort(arr,n);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

