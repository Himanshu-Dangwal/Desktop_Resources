//Paint Houses with 3 option of colours in minimum cost and 2 adjacent houses can't be painted with the same colour::

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int houses[n][3];
	for(int row = 0;row<n;row++){
		for(int col=0;col<=2;col++){
			cin>>houses[row][col];
		}
	}
	int arr[n][3];
	arr[0][0] = houses[0][0];
	arr[0][1] = houses[0][1];
	arr[0][2] = houses[0][2];
	
	for(int row = 1;row<n;row++){
		for(int col =0;col<=2;col++){
			if(col == 0){
				arr[row][col] = houses[row][col] + min(arr[row-1][1],arr[row-1][2]); 
			}else if(col ==1){
				arr[row][col] = houses[row][col] + min(arr[row-1][0],arr[row-1][2]); 
			}else if(col == 2){
				arr[row][col] = houses[row][col] + min(arr[row-1][1],arr[row-1][0]); 
			}
		}
	}
	//Finding the minimum value in arr in the last row i.e (n-1)th row::
	int min_val = INT_MAX;
	for(int i=0;i<=2;i++){
		if(arr[n-1][i]<min_val)
			min_val = arr[n-1][i];
	}
	cout<<min_val<<endl;
}
