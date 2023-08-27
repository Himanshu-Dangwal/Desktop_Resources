 //PErmutation of palindromic string:::

#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
	return (char)(i+97);
}

void permutation_palindrome(string str){
	map<char,vector<int>> m;
	int count;
	int ans[str.length()];
	for(int i=0;i<str.length();i++){
		m[str[i]].push_back(i);
	}
	for(int i=0;i<26;i++){
		count=0;
		if((m[getChar(i)].size()%2)!=0)
			count++;
	}
	if(count>=2){
		cout<<endl<<"-1"<<endl;
	}
	else{
	
		int start=0;
		int end=str.length()-1;
		for(int i=0;i<26;i++){
			for(int j=0;j<m[getChar(i)].size();j+=2){
				if((m[getChar(i)].size()-j)==1){
					ans[str.length()/2]==m[getChar(i)][j];
				}else{
					ans[start]=m[getChar(i)][j];
					ans[end]=m[getChar(i)][j+1];
				}
			start++;
			end--;	
			}
		}
	}
	for(int i=0;i<str.length();i++){
		cout<<ans[i]+1;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		permutation_palindrome(str);
	}
	return 0;
}
