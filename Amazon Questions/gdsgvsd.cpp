
#include<bits/stdc++.h>
using namespace std;

char* fun(char* str,char x){
	vector<int> freq(26,0);
	
	for(int i=0;str[i];i++){
		freq[str[i]-'a']++;
	}
	
	int maxi = 0;
	char ch;
	for(int i=0;i<26;i++){
		if(freq[i] > maxi){
			maxi = freq[i];
			ch = i + 'a';
		}
	}
	string s;
	for(int i=0;str[i];i++){
		
		if(str[i] == ch){
			s += x;
			continue;
		}
		s += str[i];
	}
	
	char* ans;
	ans = &s[0];
	return ans;
}

int main(){
	char *str = "abcccd";
	char ch = 'z';
	
	cout<<fun(str,ch);
}
