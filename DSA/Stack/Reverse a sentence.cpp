//Reverse A Sentence Using Stack::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void reverseSentence(string s){
	
	stack<string> st;
	for(int i=0;i<s.length();i++){
		string word = "";
		while(s[i] != ' ' && i < s.length()){
			word += s[i];
			i++;
		}
		st.push(word);
	}
	
	while(!st.empty()){
		string s = st.top();
		st.pop();
		
		cout<<s<<" ";
	}
	cout<<endl;
}

int main(){
	string s = "Hey I am Himanshu";
	reverseSentence(s);

	return 0;
}

