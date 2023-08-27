#include<bits/stdc++.h>
using namespace std;

void printPermutations(string s,string ans){
	
	if(s.length() == 0){
		cout<<ans<<endl;
		return;
	}
	
	for(int i=0;i<s.length();i++){
		char ch = s[i];
		string left = s.substr(0,i);
		string right = s.substr(i+1);
		
		string concatenated = left + right;
		printPermutations(concatenated,ch+ans);
	}
	
}

int main(){
	string s;
	cin>>s;
	
	
	string ans = "";
	printPermutations(s,ans);

	return 0;
}


