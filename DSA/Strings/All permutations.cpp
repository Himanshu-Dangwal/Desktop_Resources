#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void permutations(string s,string ans){
	
	if(s.length() == 0){
		cout<<ans<<endl;
		return;
	}
	
	
	for(int i=0;i<s.length();i++){
		char ch = s[i];
		string left = s.substr(0,i);
		string right = s.substr(i+1);
		
		string concatenated = left + right;
		
		permutations(concatenated,ans + ch);
	}
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin>>s;
	string ans = "";
	permutations(s,ans);
	
	return 0;
}

