#include<iostream>
using namespace std;

int longestBitonicSubarray( int *arr, int n ) {
    int inc[n];
    int dec[n];
    inc[0]=1;
    dec[n-1]=1;
    
    for(int i=1;i<n;i++){
        inc[i] = (arr[i]>arr[i-1])?inc[i-1]+1 : 1;
    }
    for(int i=0;i<n;i++){
    	cout<<inc[i] ;
	}
	
    for(int i=n-2;i>=0;i--){
        dec[i] = (arr[i]>arr[i+1])?dec[i+1]+1: 1;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
    	cout<<dec[i];
	}
    int max = inc[0] + dec[0] -1;
    for(int i=1;i<n;i++){
       if(inc[i]+dec[i]-1 > max){
           max = inc[i]+dec[i]-1;
       }
    }
   return max;
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}


