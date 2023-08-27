//Check Whether ith bit of a number is set or unset:::

/*
Logic::
	I will use & operation and multiply the number with number 2^i;;
	
	Ex => 5 = 00000101
	i=2
	2^2=4
	
	4 = 00000100
	
	5 & 4 = 00000100 !=0 Which tells that ith bit is set to 1::
	
			if 5 = 00000101
	 bits number = 76543210 
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int N,int i){
	int k = N & (1<<i);
	if(k==0){
		return true;
	}
	return false;
}

int main(){
	int N;
	int bitNumber;
	cin>>N>>bitNumber;
	if(check(N,bitNumber)){
		cout<<"false"; //Indicating that the bit is unset ..i.e bit at ith position of number N is 0
	}else{
		cout<<"true";
	}
}	 
	 
