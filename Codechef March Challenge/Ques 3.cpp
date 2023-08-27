#include<bits/stdc++.h>
using namespace std;

int getDecimal(int *arr,int size){
	int count=0;
	for(int i=0;i<size;i++){
		count+=arr[i]*(pow(2,i));
	}
	return count;
}

int main(){
	int t;
	cin>>t;
	int arr[t];
	int n = 0;
	int y=t;
	while(t--){
		int c;
		
		cin>>c;
		int pos =  ceil(log2(c));
		int value = pow(2,pos);
		int a[pos];
		int b[pos];
		for(int i=0;i<pos;i++){
			if((c & (1<<i)) == 0){
				a[i]=1;
				b[i]=1;
			}else{
				if(i==pos-1){
					a[i]=1;
					b[i]=0;
				}
				else{
					a[i]=0;
					b[i]=1;
				}
			}
		}
		int first = getDecimal(a,pos);
		int second = getDecimal(b,pos);
		//arr[n-t]=(first*second);
		arr[n] = (first*second);
		++n;
	}
	for(int y=0;y<n;y++){
	    cout<<arr[y]<<endl;
	}
}
