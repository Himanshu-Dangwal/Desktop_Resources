//Best Time to buy and sell 2 transactions allowed (HARD):::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	//Traverse left to right::
	int ltr[n];
	int min_till_now = arr[0];
	ltr[0] = 0;
	for(int i=1;i<n;i++){
		if(arr[i] < min_till_now){
			min_till_now = arr[i];
		}
		ltr[i] = max(ltr[i-1],arr[i] - min_till_now);
	}
	
	//Traverse from right to left::
	int rtl[n];
	rtl[n-1] = 0;
	int max_after_today = arr[n-1];
	for(int i=n-2;i>=0;i--){
		if(arr[i] > max_after_today){
			max_after_today= arr[i];
		}
		rtl[i] = max(rtl[i+1],max_after_today - arr[i]);
	}
	//Adding all values and finding the maximum till now::
	int max_till_now = INT_MIN;
	for(int i=0;i<n;i++){
		if((ltr[i] + rtl[i]) > max_till_now){
			max_till_now = ltr[i] + rtl[i];
		}
	}
	cout<<max_till_now<<endl;
	return 0;
}

