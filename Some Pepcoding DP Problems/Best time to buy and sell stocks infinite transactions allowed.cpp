//Best TIme to Buy And Sell Stocks ::
//INfinite Transactions allowed without overlapping::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int profit = 0;
	int b = arr[0];   //Buy
	int s = arr[0];	  //Sell
	
	
	for(int i=1;i<n;i++){
		if(arr[i] >= s)
			s = arr[i];
		else{
			profit += s - b;
			b = arr[i];
			s = arr[i];
		}	
	}
	
	
	profit += s-b;
	cout<<profit<<endl;
	return 0;
}

