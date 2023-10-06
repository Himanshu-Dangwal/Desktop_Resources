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


//abcabcdeabde
//000123001200

vector<int> getLPS(string pattern){
	vector<int> lps(pattern.length(),0);
	
	int i=1,j=0;
	
	while(i < pattern.length()){
		if(pattern[i] == pattern[j]){
			lps[i] = j+1;
			i++;
			j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	return lps;
}


void KMP(string text,string pattern){
	vector<int> lps = getLPS(pattern);
	
	int i=0,j=0;
	
	while(i < text.length() && j < pattern.length()){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	
	if(j == pattern.length()){
		cout<<"Matched at index = "<<i-j<<endl;
	}
	
}

int main(){
	
	string text,pattern;
	cin>>text>>pattern;
	
	KMP(text,pattern);
	
	return 0;
}


//Wifi Password : NS@Incanus


