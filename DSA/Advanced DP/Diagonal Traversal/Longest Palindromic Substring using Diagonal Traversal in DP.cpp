//Longest Palindromic Subsequence using Diagonal Traversal DP
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


int main(){
	string s;
	cin>>s;
	
	int dp[s.length()][s.length()];
	
	int omax = 0;
	
	for(int g=0;g<s.length();g++){
		for(int i=0,j=g; j < s.length();i++,j++){
			if(i == j){          //d0   diagonal 0
				dp[i][j] = true;
			}else if(g == 1){    //d1   diagonal 1
				if(s[i] == s[j]){
					dp[i][j] = true;
				}else{
					dp[i][j] = false;
				}
			}else{
				if(s[i] == s[j]){
					if(dp[i+1][j-1] == true){
						dp[i][j] = true;
					}else{
						dp[i][j] = false;
					}
				}else{
					dp[i][j] = false;
				}
			}
			
			if(dp[i][j])
				omax = g + 1;
		}
	}
	
	cout<<omax<<endl;
	return 0;
}

