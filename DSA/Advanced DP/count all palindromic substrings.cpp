#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

string convert(string s){
	
	string temp = s.substr(0,1);

	int j = 0;
	for(int i=1;i<s.length();i++){
		if(s[i] != temp[j]){
			temp += s[i];
			j++;
		}
	}
	return temp;
}

bool palindrome(string s){
	int i=0,j=s.length()-1;
	while(s[i] == s[j] && i<=j){
		i++;
		j--;
	}
	if(i < j) return false;
	return true;
}

int main(){
	string s;
	cin>>s;
	
	unordered_set<string> ss;
	int even = 0,odd = 0;
	
	for(int i=0;i<s.length();i++){
		int l=i,r=i;
		while(l >=0 && r < s.length() && s[l] == s[r]){
			ss.insert(s.substr(l,r-l+1));
			odd++;
			l--;
			r++;
		}
		
		l = i;
		r = i+1;
		while(l >= 0 && r < s.length() && s[l] == s[r]){
			ss.insert(s.substr(l,r-l+1));
			even++;
			l--;
			r++;
		}
	}
	
	cout<<even<<" "<<odd<<endl;
	//Generate all possible substrings not in the set and compress them if after compressing they are palindrome them odd count corresponding to the length of uncompressed string::
	
	//O(n^3)
	/*
	for(int i=0;i<s.length()-2;i++){
		for(int j=i+2;j<s.length();j++){
			string temp = s.substr(i,j-i+1);
			if(ss.find(temp) == ss.end()){
				//compress it and check for palindrome::
				string converted = convert(temp);

				if(palindrome(converted)){  //if converted is palindrome
					if(temp.size()%2 == 0) even++;
					else odd++;
				}
			}
		}
	}
	*/
	
	
	
	cout<<even<<" "<<odd;
	return 0;
}

