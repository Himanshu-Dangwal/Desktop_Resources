//Longest Palindromic Substring::
#include<bits/stdc++.h>
using namespace std;

int lps(string s){
	int n = s.length();
	int max_val = 0;;
	for(int i=0;i<n;i++){
		//Odd Length ::
		int l=i;
		int r = i;
		while(l>=0 && r<n && s[l] == s[r]){
			max_val =  max(max_val,r-l+1);
			l--;
			r++;
		}

		//Even Length ::
		l = i;
		r = i+1;
		while(l>=0 && r<n && s[l] == s[r]){
			max_val =  max(max_val,r-l+1);
			l--;
			r++;
		}

	}
	return max_val;
}

int main(){
	string s;
	cin>>s;
	cout<<lps(s);
	return 0;
}
