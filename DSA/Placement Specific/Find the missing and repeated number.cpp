//Find the missing and repeating number::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
/*
int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int s = (n*(n+1))/2;
	int p = (n*(n+1)*(2*n + 1))/6;
	
	for(int i=0;i<n;i++){
		s -= arr[i];
		p -= arr[i] * arr[i];
	}
	
	int missing_number = (p/s + s)/2;
	int repeated_number = missing_number - s;
	
	cout<<missing_number<<" "<<repeated_number<<endl;
	return 0;
}

*/
//Approach 2::

//Using XOR
int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int xor1 = 0;
	
	for(int i=1;i<=n;i++){
		xor1 = xor1 ^ i;
		xor1 = xor1 ^ arr[i-1];
	}
	
	//Now xor1 will have missing ^ repeated 
	//Find the rightmost set bit and make 2 seaparate baskets::
//	cout<<"XOR1 = "<<xor1<<endl;
	int set_bit = xor1 & ~(xor1 - 1);
//	cout<<"Set Bit = "<<set_bit<<endl;
	int missing =  0;  //basket1
	int repeated = 0;  //basket2
	for(int i=0;i<n;i++){
		if(arr[i] & set_bit)
			missing = missing ^ arr[i];
		else
			repeated = repeated ^ arr[i];	
	}
//	cout<<missing<<" "<<repeated<<endl;
	for(int i=1;i<=n;i++){
		if(i & set_bit){
			missing = missing ^ i;
//			cout<<i<<endl;
		}
			
		else
			repeated = repeated ^ i;	
	}
	
	int counter_for_x = 0;
	
	for(int i=0;i<n;i++){
		if(arr[i] == missing){
			counter_for_x++;
			break;
		}
	}
	
	if(counter_for_x){
		cout<<"missing = "<<repeated<<"repeated = "<<missing;
	}else{
		cout<<"missing = "<<missing<<"repeated = "<<repeated;
	}
		
	return 0;	
		
	
}



















