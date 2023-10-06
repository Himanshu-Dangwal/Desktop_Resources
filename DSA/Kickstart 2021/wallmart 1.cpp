#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	
	string pattern = "BAZINGA";
	int len = pattern.length();
	
	while(t--){
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		int p1 = 0,p2 = 0;
		
		while(p1 < n && p2 < len){
			if(s[p1] == pattern[p2]){
				p1++;
				p2++;
			}else{
				p1++;
			}
		}
		
		if(p2 == len){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}






















