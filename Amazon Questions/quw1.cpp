#include<bits/stdc++.h>
using namespace std;


int main(){

	string s;
	cin>>s;
	
	string temp = "";
	int n = s.length();
	int cnt = 0;
	for(int i=0;i<n;){
		
		if(i != 0){
			if(s[i] != s[i-1]) cnt = 0;
		}
		
		if(cnt == 0){
			cnt++;
			temp += s[i];
			i++;
		}else{
			if(cnt < 2){
				cnt++;
				temp += s[i];
				i++;
			}else{
				while(i < s.length() && s[i] == s[i-1]) i++;
				cnt = 0;
			}
		}
	}

	cout<<temp;

	return 0;
}


