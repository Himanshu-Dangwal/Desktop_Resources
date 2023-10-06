//Heap And Heap Sort

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void heapify(int arr[],int n,int i){
	
	int left_child = 2*i + 1;
	int right_child = 2*i + 2;
	int largest = i;
	
	if(left_child < n && arr[left_child] > arr[largest]){
		largest = left_child;
	}
	if(right_child < n && arr[right_child] > arr[largest]){
		largest = right_child;
	}
	if(largest != i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[],int n){
	
	for(int i=(n/2 -1);i>=0;i--){
		heapify(arr,n,i);
	}
	
	cout<<endl;
	cout<<"After Heapify "<<endl;
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	
	for(int i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
		
		heapify(arr,i,0);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	heapSort(arr,n);
	
	cout<<endl;
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}

