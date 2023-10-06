//Print all permutations of a string::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void printPermutations(string s,string ans){
	
	if(s.length() == 0){
		cout<<ans<<endl;
		return;
	}
	
	for(int i=0;i<s.length();i++){
		char ch = s[i];
		string left = s.substr(0,i);
		string right = s.substr(i+1);
		
		string rem = left+right;
		printPermutations(rem,ans + ch);
	}
	
}

int main(){
	string s;
	cin>>s;
	
	string ans  = "";
	printPermutations(s,ans);

	return 0;
}

