//BEst TIme to Buy and Sell Stocks::
//Infinite Transactions + Transaction Fees::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	int fees;
	cin>>fees;
	
	int ob = 0-arr[0];   //Old Buy
	int os = 0;			//Old Sell	

	for(int i=1;i<n;i++){
		int nb = 0;			//New Buy
		int ns = 0;			//New Sell
		nb = max(ob,os - arr[i]);
		ns = max(os,ob + arr[i] - fees);
		
		ob = nb;
		os = ns;
	}
	cout<<os<<endl;
	return 0;
}

