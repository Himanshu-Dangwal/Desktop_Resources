//Removing a particular character from a character array::

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

void removeX(char s[]){
	if(s[0] == '\0'){
		return;
	}
		if(s[0] != 'x'){
			removeX(s+1);
		}else{
			int i=1;
			for(;s[i]!='\0';i++){
				s[i-1]=s[i];
			}
			s[i-1]=s[i];
			removeX(s);
		}
}


int main(){
	int s[100];
	cin>>s;
	int l=length(s);
	cout<<l<<endl;
	removeX(s);
	cout<<s<<end;
	l=length(s);
	cout<<l<<endl;
	return 0;
}
