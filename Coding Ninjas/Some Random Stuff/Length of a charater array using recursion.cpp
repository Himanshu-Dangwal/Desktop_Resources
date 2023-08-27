//Legth Of a string using recursion::

#include<bits/stdc++.h>
using namespace std;

int length(char s[]){
	if(s[0]=='\0'){
		return 0;
	}else{
		int smallAns=length(s+1);
		return 1+smallAns;
	}
}

int main(){
	char s[100];
	cin>>s;
	int l = length(s);
	cout<<l<<endl;
}
