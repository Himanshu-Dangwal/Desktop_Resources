//In a givern string find the firdt non repeating character::
#include<bits/stdc++.h>
using namespace std;

char nonRepeatingCharacter(string str){
	map<char,int> m;
	for(int i=0;i<str.length();i++){
		m[str[i]]++;
	}
	for(int i=0;i<str.length();i++){
		if(m[str[i]]==1)
			return str[i];
	}
	return str[0];
}

int main(){
	string str;
	cin>>str;
	cout<<nonRepeatingCharacter(str)<<endl;
	return 0;
}
