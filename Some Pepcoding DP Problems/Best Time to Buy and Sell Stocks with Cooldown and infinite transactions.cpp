//Best time to buy and sell stocks with cooldown::
// cooldown -> Buy
// Buy - > Sold
// Sold - > Cooldown
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int bsp = 0-arr[0];  //Buy State Price::
	int ssp = 0;		//Sold State Price::
	int csp = 0;		//Cooldown State Price::

	for(int i=1;i<n;i++){
		int nbsp = 0;
		int nssp = 0;
		int ncsp = 0;
		
		nbsp = max(bsp,csp - arr[i]);
		nssp = max(ssp,bsp + arr[i]);
		ncsp = max(csp,ssp);
		
		bsp = nbsp;
		ssp = nssp;
		csp = ncsp;
	}
	cout<<ssp<<endl;
	return 0;
}

