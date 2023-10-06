//Longest Palindromic Substring::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int longestPalindromicSubstring(string s){
	
	int max_val = 0;
	int n = s.length();
	for(int i=0;i<n;i++){
		
		int l = i;
		int r = i;	
		
		//Odd length::
		while(l>=0 && r<n && s[r] == s[l]){
			max_val = max(max_val,r-l+1);
			l--;
			r++;
		}
		
		l = i;
		r = i+1;
		
		while(l>=0 && r<n && s[r] == s[l]){
			max_val = max(max_val,r-l+1);
			l--;
			r++;
		}
	}
	return max_val;
}

int main(){
	string s;
	cin>>s;
	
	cout<<longestPalindromicSubstring(s)<<endl;

	return 0;
}

