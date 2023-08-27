//Recursions and strings::
//Length of a character array using recursion
#include<iostream>
using namespace std;

int length(char s[]){
	
	//base case:
	if(s[0]=='\0'){
		return 0;
	}
	//small calculation and recursive call
 	int smallAns=length(s+1);
	return 1+smallAns;
}

void removeX(char s[]){
	if(s[0]=='\0'){
		return;
	}
	if(s[0]!='x'){
		removeX(s+1);
	}else{
		int i=1;
		for(;s[i]!='\0';i++){
			s[i-1]=s[i];
		}
		s[i-1]='\0';
		removeX(s+1);
	}
}

int main(){
	char s[100];
	cin>>s;
	int l = length(s);
	cout<<l<<endl;
	removeX(s);
	cout<<s;
	return 0;
}

I am currently having an internship at coding ninjas.I am working as a campus ninja in this  programme.I am always trying to learn new thngs,and these type of internships are helping me a lot to boost up myself and gain a ton load of confidence.
