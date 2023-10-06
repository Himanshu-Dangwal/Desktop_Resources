//Count Distict palindromic Subsequences::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	string s;
	cin>>s;
	
	int next[s.length()];
	int prev[s.length()];
	
	unordered_map<char,int> m;
	
	for(int i=0;i<s.length();i++){
		if(m.find(s[i]) == m.end()){
			prev[i] = -1;
		}else{
			prev[i] = m[s[i]];
		}
		m[s[i]] = i;
	}
	unordered_map<char,int> mp;
	for(int i=s.length()-1;i>=0;i--){
		if(mp.find(s[i]) == mp.end()){
			next[i] = -1; 
		}else{
			next[i] = mp[s[i]];
		}
		mp[s[i]] = i;
	}

	int dp[s.length()][s.length()];
	
	for(int i=0;i<s.length();i++){
		for(int j=0;j<s.length();j++){
			dp[i][j] = 0;
		}
	}
	
	
	for(int g=0;g<s.length();g++){
		for(int i=0,j=g;j<s.length();i++,j++){
			
			if(g == 0){
				dp[i][j] = 1;	
			}else if(g == 1){
				dp[i][j] = 2;
			}else{
				if(s[i] != s[j]){
					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
				}else{
					int n = next[i];
					int p = prev[j];
					
					if(n == p){
						dp[i][j] = 2*dp[i+1][j-1] + 1;
					}else if(n > p){
						dp[i][j] = 2*dp[i+1][j-1] + 2;
					}else{
						dp[i][j] = 2*dp[i+1][j-1] - dp[n+1][p-1];
					}
				}
			}
		}
	}
	
	for(int i=0;i<s.length();i++){
		for(int j=0;j<s.length();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<dp[0][s.length()-1]<<endl;
	
	return 0;
}
