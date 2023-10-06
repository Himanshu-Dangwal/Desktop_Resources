//Count Palindromic Subsequences::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

//If c1 == c2  then c(s) = c(c1m) + c(mc2) + 1;
//Else   c(s) = c(c1m) + c(mc2) - c(m);

int main(){
	string s;
	cin>>s;
	
	int dp[s.length()][s.length()];
	
	for(int g=0;g<s.length();g++){
		for(int i=0,j=g;j<s.length();i++,j++){
			if(g == 0){
				dp[i][j] = 1;
			}else if(g==1){
				if(s[i] == s[j]){
					dp[i][j] = 3;
				}else{
					dp[i][j] = 2;
				}
			}else{
				if(s[i] == s[j]){
					dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
				}else{
					dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
				}
			}
		}
	}
	
	cout<<dp[0][s.length()-1]<<endl;
	return 0;
}

