//Regex Matching
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	string text,pattern;
	/*
	text = mississippi  
	pattern = mis*i.*p*i
	
	. can take any characater::
	* can be used with the character before it and can replicate it any number of times ,even 0 times
	*/ 
	cin>>text>>pattern;

	bool dp[pattern.length()+1][text.length()+1];
	
	for(int i=0;i<=pattern.length();i++){
		for(int j=0;j<=text.length();j++){
			if(i==0 && j==0){
				dp[i][j] = true;
			}else if(i==0){
				dp[i][j] = false;
			}else if(j==0){
				if(pattern[i-1] == '*' && i-2 >=0){
					dp[i][j] = dp[i-2][j];
				}else{
					dp[i][j] = false;
				}
			}else{
				if(pattern[i-1] == '.'){
					dp[i][j] = dp[i-1][j-1];
				}else if(pattern[i-1] == '*'){
					dp[i][j] = dp[i-2][j];
					if(pattern[i-2] == text[j-1] || pattern[i-2] == '.'){
						dp[i][j] = dp[i][j] || dp[i][j-1];
					}
				}else{
					if(pattern[i-1] == text[j-1]){
						dp[i][j] = dp[i-1][j-1];
					}else{
						dp[i][j] = false;
					}
				}
			}
		}
	}
	
	cout<<dp[pattern.length()][text.length()]<<endl;
	return 0;
}

