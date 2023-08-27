#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int cmp;

void init(){
	cmp =0;
}
void merge(int input[],int start,int mid,int end){
    int temp[end-start+1];
    int i=start;
    int j=mid;
    int k=0;
    while(i<mid && j<=end){
        cmp++;
		if(input[i]<input[j]){
            temp[k++]=input[i++];
        }else{
            temp[k++]=input[j++];
        }
    }
    while(i<mid){
        temp[k++]=input[i++];
    }
    while(j<=end){
        temp[k++]=input[j++];
    }
    for(i=start,k=0;i<=end;i++,k++){
        input[i]=temp[k];
    }
}

void merge_sort(int input[],int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(input,start,mid);
        merge_sort(input,mid+1,end);
        merge(input,start,mid+1,end);
    }
}
void mergeSort(int input[], int size){
	// Write your code here
        if(size==0 || size==1){
            return;
        }
    	int start = 0;
    	int end = size-1;
    	merge_sort(input,start,end);
}


int main() {
  int t;
  cin>>t;
  while(t--){
  	  int length;
	  cin >> length;
	  int* input = new int[length];
	  for(int i=0; i < length; i++)
	    cin >> input[i];
	  init();  
	  mergeSort(input, length);
	  for(int i = 0; i < length; i++) {
	    cout << input[i] << " ";
	  }
	  cout<<endl;
	  cout<<cmp<<endl;	
  }
}
