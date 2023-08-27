#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int cmp;
int swaps;

void init(){
	cmp = 0;
	swaps =0;
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr,int low,int high){
    int pivot = arr[high];
    int i = (low-1);
    for(int j=low;j<high;j++){
    	cmp++;
        if(arr[j] <= pivot){
            swaps++;
			i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swaps++;
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

int partition_r(int* input,int low,int high){
	
	srand(time(NULL));
	int random = low + rand() % (high - low);
	
	swap(&input[random],&input[high]);
	
	return partition(input,low,high);
}

void quick(int *input,int low,int high){
    if(low<high){
        int pi = partition_r(input,low,high);
        quick(input,low,pi-1);
        quick(input,pi+1,high);
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int* input = new int[n];
		for(int i=0;i<n;i++){
			cin>>input[i];
		}
		cout<<endl;
		init();
		quick(input,0,n-1);
		for(int i=0;i<n;i++){
			cout<<input[i]<<" ";
		}
		cout<<endl;
		cout<<"Comaparision = "<<cmp<<endl;;
		cout<<"Swaps = "<<swaps<<endl;
		cout<<endl;
	}
}
