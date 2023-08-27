//Best Time to Buy And Sell Stocks ::
// One Transaction Allowed::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max_profit = INT_MIN;
	int pist = 0;   //Profit if sold today::
	int min_val = INT_MAX;
	for(int i=0;i<n;i++){
		if(arr[i] < min_val){
			min_val = arr[i];
		}
		pist = arr[i] - min_val;
		if(pist > max_profit){
			max_profit = pist;
		}
	}
	cout<<max_profit<<endl;
	return 0;
}

