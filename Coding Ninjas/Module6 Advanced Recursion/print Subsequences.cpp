//printing All subsequences of a string:::
#include<bits/stdc++.h>
using namespace std;

void printSubsequences(string s,string output){
	if(s.size()==0){
		cout<<output<<endl;
		return;
	}
	printSubsequences(s.substr(1),output);
	printSubsequences(s.substr(1), output+s[0]);
	return;
}

int main(){
	string s;
	cin>>s;
	string output = "";
	printSubsequences(s,output);
	return 0;
}


								/*"ab"
						
						"b" ""      "b" "a"
						
				""  "b"  "" ""	        ""  "a"    "" "ab"	*/
