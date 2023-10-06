//Count Palindromic Subsequences::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

//Longest Palindromic Subsequence
int main(){
	string s;
	cin>>s;
	
	int dp[s.length()][s.length()];
	
	int omax = 0;
	
	for(int g=0;g<s.length();g++){
		for(int i=0,j=g;j<s.length();i++,j++){
			if(g == 0){
				dp[i][j] = 1;
			}else if(g==1){
				if(s[i] == s[j]){
					dp[i][j] = 2;
				}else{
					dp[i][j] = 1;
				}
			}else{
				if(s[i] == s[j]){
					dp[i][j] = 2 + dp[i+1][j-1];
				}else{
					dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
				}
			}
			if(dp[i][j] > omax)
				omax = dp[i][j];
		}
	}
	
	cout<<omax<<endl;
	return 0;
}

