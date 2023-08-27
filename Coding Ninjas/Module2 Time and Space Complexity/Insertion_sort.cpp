//Code for insertion Sort:::
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *A,int n){
	int j,temp;
	for(int j=1;j<n;j++){
		for(int i=j-1;i>=0;i--){
			if(A[i+1]<A[i]){
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
			}
		}
	}
}


int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	insertion_sort(A,n);
	for(int i=0;i<n;i++){
		cout<<A[i]<<endl;
	}
}

   /*6 1 8 2 4
   i j
    
   1 6 8 2 4
         j*/
