//Variation Count::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int left , right ,count=0;
	left = 0;
	right = 1;
	while(right != n){
		if(left == right){
			right++ ;
		}
		if(right == n){
			break;
		}
		if((a[right] - a[left])  >=  k ){
			count += n - right ;
			left++ ;
		}
		else
			right++ ;
	}
	cout<<count;
}
