#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int num1,num2;
	cin>>num1>>num2;
	
	int cnt = 0;
	while(num1 && num2){
		if(num1 >= num2){
			num1 -= num2;
		}else{
			num2 -= num1;
		}
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

