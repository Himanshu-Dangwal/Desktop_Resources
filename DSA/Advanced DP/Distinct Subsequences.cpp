z//Count Distinct Subsequences::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	string s;
	cin>>s;
	
	int dp[s.length()+1];
	dp[0] = 1;   //If length = 0 then 1 subsequnce possible i.e ""  empty string
	
	unordered_map<char,int> m;
	
	for(int i=1;i<=s.length();i++){
		dp[i] = 2*dp[i-1];
		
		if(m.find(s[i-1]) != m.end()){
			int dp_idx = m[s[i-1]];
			dp[i] = dp[i] - dp[dp_idx - 1];
		}
		m[s[i-1]] = i;
	}
	
	cout<<dp[s.length()];

	return 0;
}

