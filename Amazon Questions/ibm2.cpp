#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	
	while(n > 10){
		int sum = 0;
		int num = n;
		while(num){
			sum += num%10;
			num /= 10;
		}
//		cout<<sum<<endl;
		n = sum;
	}
//	cout<<n;
	if(n == 1 || n == 10) cout<<1;
	else cout<<0;
}


