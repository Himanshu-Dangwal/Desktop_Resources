//All pairs in a vector of strings that can form a palindrome::

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define PII pair<int,int>

bool isPalindrome(string s){
	int n =s.length();
	
	int i=0;
	int j=n-1;
	
	while(i<j){
		if(s[i] != s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}


int main(){
	vector<string> words;
	int n;
	cin>>n;
	//Map to store strings corresponding to theier indices::
	map<string,int> m;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		words.push_back(s);
		m[s] = i;
	}
	
	//Vector of pairs to store the indices of pair of strings which forms a palindrome::
	
	vector<PII> ans;
	
	//Check if "" empty character exists or not::
	string str = "";
	if(m.find(str) != m.end()){
		int idx = m[str];
		for(int i=0;i<words.size();i++){
			if(i != idx && isPalindrome(words[i])){
				ans.push_back(make_pair(i,idx));
				ans.push_back(make_pair(idx,i));
			}
		}
	}
	
	//If reverse of a word exists in the map::
	
	for(int i=0;i<words.size();i++){
		string curr = words[i];
		string copy_for_curr = curr;
		reverse(copy_for_curr.begin(),copy_for_curr.end());
		
		string rev = copy_for_curr;
		
		if(m.find(rev) != m.end() && m[rev] != i){
			ans.push_back(make_pair(i,m[rev]));
		}
		
	}
	
	// IF str1 prefix is a palindrome and the remaining suffix of string 1 is reverse of a string already present in the map ans str2::
	// In that case The palindrome would be formed as - >   str2 + str1(prefix) + str1(suffix)         
	
	// Also, If the suffix of str1 is a palindrome and the prefix of str1 is already present in the map...
	// In that case The palindrome would be formed as - >   str1 + str2
	
	for(int i=0;i<words.size();i++){
		string curr = words[i];
		
		for(int cut = 1;cut < curr.length();cut++){
			string left = curr.substr(0,cut);
			string right = curr.substr(cut);
			
			if(isPalindrome(left)){
				string copy_for_right = right;
				reverse(copy_for_right.begin(),copy_for_right.end());
				
				string rev = copy_for_right;
				
				if(m.find(rev) != m.end()){
					ans.push_back(make_pair(m[rev],i));
				}
			}
			
			if(isPalindrome(right)){
				
				string copy_for_left = left;
				
				reverse(copy_for_left.begin(),copy_for_left.end());
				string rev = copy_for_left;
				
				if(m.find(rev) != m.end()){
					ans.push_back(make_pair(i,m[rev]));
				}
			}
			
		}

	}
		
	//Print all pairs::
	
	for(auto it : ans){
		
		int firstIdx = it.first;
		int secondIdx = it.second;
		
		cout<<words[firstIdx]<<" "<<words[secondIdx]<<endl;
		
	}	
	
	return 0;
}

