#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)

int ans = 0;

void solve(){
	string s,p;
	cin>>s>>p;
	
	
	unordered_map<char,int> mp1;
	unordered_map<char,int> mp2;
	unordered_set<char> st;
	for(char c : s){
		mp1[c]++;
	}
	
	for(char c : p){
		mp2[c]++;
		st.insert(c);
	}
	bool isPossible = false;
	if(s.length() > p.length()){
		ans = -1;
		return;
	}
	int len = 0;
	if(s.length() < p.length()){
		isPossible = true;
		len = p.length() - s.length();
	}
	
	int req = 0;
	for(auto x : st){
		if(mp1.find(x) != mp1.end()){
			if(mp1[x] > mp2[x]){
				ans = -1;
				return;
			}else{
				req += mp2[x] - mp1[x];
			}
		}else{
			req += mp2[x];
		}
	}
	
	if(req > len){
		ans = -1;
		return;
	}	
	
	for(int i=0;i<s.length();i++){
		char ch = s[i];
		if(mp2.find(ch) == mp2.end()){
			ans = -1;
			return;
		}else{
			if(mp2[ch] < mp1[ch]){
				ans = -1;
				return;
			}
		}
	}
	
	ans = len;
	return;
	
}

int main(){
	int t;
	cin>>t;
	int  i = 1;
	while(t--){
		solve();
		if(ans != -1)
			cout<<"Case #"<<i<<": "<<ans<<endl;
		else
			cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
		i++;
	}


	return 0;
}


