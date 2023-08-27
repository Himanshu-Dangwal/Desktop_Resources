//Fenwick tree Code:::
//Used in range and update queries problems::
#include<bits/stdc++.h>
using namespace std;

void update(int index,int val,int *BIT,int n){
	for(;index<=n;index+=(index & (-index))){
		BIT[index] += val;
	}
}

int query(int index,int *BIT){
	int sum = 0;
	for(;index>0;index-=(index & (-index))){
		sum+=BIT[index];
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n+1]();
	int *BIT = new int[n+1]();
	//Taking the array values as input::from index 1
	for(int i=1;i<n+1;i++){
		cin>>arr[i];
		update(i,arr[i],BIT,n);
	}
	int q;
	//Enter the number of queries::
	cin>>q;
	while(q--){
		//Enter the index i.e the left and right boundaries between which we want to find out the sum::
		int a,b;
		cin>>a>>b;
		cout<<query(b,BIT) - query(a-1,BIT)<<endl;
	}
}
