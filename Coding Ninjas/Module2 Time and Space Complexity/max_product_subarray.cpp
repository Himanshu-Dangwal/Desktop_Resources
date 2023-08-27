#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll max_product_subarray(int *a,int size){
	ll current_product=1;
	ll max_product=1;
	ll negative_value=1;
	
	for(int i=0;i<size;i++){
		current_product=current_product*a[i];
		if(current_product<=0)
			negative_value=current_product;
		else
			if(max_product<current_product)
				max_product=current_product;	
		if(current_product==0)
			current_product+=1;
	}
	return max_product;
}

int main(){
	//Input array and pass the array and its size in the above function::
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<max_product_subarray(a,n);
	return 0;
}
