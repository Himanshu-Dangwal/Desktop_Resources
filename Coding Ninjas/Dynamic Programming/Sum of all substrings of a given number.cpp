#include<bits/stdc++.h>
using namespace std;

int substring(string s){
	long long total_sum = s[0] - '0';
	long long last_value = s[0] - '0';
	for(int i=1;i<s.length();i++){
		last_value = last_value*10 + (s[i]-'0')*(i+1);
		total_sum += last_value;
	}
	return total_sum;
}

int main(){
	string s;
	cin>>s;
	cout<<substring(s);
	return 0;
}
