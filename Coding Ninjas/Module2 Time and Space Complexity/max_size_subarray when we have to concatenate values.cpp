/*We have to concatenate an array(of size N) k times and find the max subarray sum of the concatenated array::
	Constraints :: 1<=N<=10^5
				   1<=K<=10^5
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll max(ll a,ll b){
	if(a>b)
		return a;
	return b;	
}

ll kadane(int *array,int n){
	ll current_sum=0;
	ll best_sum=0;
	for(int i=0;i<n;i++){
		current_sum = current_sum + array[i];
		if(best_sum<current_sum){
			best_sum=current_sum;
		}
		if(current_sum<0){
			current_sum=0;
		}
	}
	return best_sum;
}

ll max_size_subarray(int *a,int n,int k){
	ll kadanes_value=kadane(a,n);
	ll current_prefix=0;
	ll best_prefix=INT_MIN;
	ll current_suffix=0;
	ll best_suffix=INT_MIN;
	
	for(int i=0;i<n;i++){
		 	current_prefix = current_prefix + a[i];
		if(best_prefix<current_prefix)
			best_prefix=current_prefix;
	}
	for(int i=n-1;i>=0;i--){
			current_suffix+=a[i];
		if(best_suffix<current_suffix)
			best_suffix=current_suffix;		
	}
	ll total_sum=current_prefix;
	if(total_sum>0)
		return max((best_prefix+best_suffix+(k-2)*total_sum),kadanes_value);
	else
		return max((best_prefix+best_suffix),kadanes_value);	
}

int main(){
	int t,k,n;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<max_size_subarray(a,n,k)<<endl;
	}	
}









/*
	intput number of test cases;
	loop for each test case:
		Input: array size,and k
			   array elements
			   call function max_size_subarray
	
	function max_size_subarray::
		 kadanes_value=kadane(array,size)
		 current_prefix=0
		 best_prefix=0
		 current_suffix=0
		 best_sufffix=0
		 
		 for prefix;
		 	loop iterating through the array:
				 	current_prefix+=a[i]
				if(best_prefix<current_prefix)
					best_prefix=current_prefix
					
		for suffix:
			loop reverse iterating through the array:
				 	current_suffix+=a[i]
				if(best_suffix<current_suffix)
					best_suffix=current_suffix
					
		//All are long long values:::
		
		total_sum=current_prefix::
		
		if(total_sum>0){
			return max(best_prefix+best_suffux+(k-2)*total_sum),kadanes_value);
		else
			return((best_prefix+best_suffix),kadanes_value);	
	}
*/	
