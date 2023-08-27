/*/

React Python Ansi-C javascript Python Ansi-C Java Python Java React Ansi-C javascript Ansi-C Ansi-C React Java React


/*/



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

class help{
	public:
		string word;
		int cnt;
};

bool cmp(help a,help b){
	if(a.cnt != b.cnt){
		return a.cnt > b.cnt;
	}
	
	return a.word < b.word;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin,s);
	
	stringstream str(s);
	string word;
	
	unordered_map<string,int> mp;
	
	while(str >> word){
		mp[word]++;
	}
	
	vector<help> arr;
	
	for(auto it : mp){
		help a;
		a.word = it.first;
		a.cnt = it.second;
		arr.push_back(a);
	}
	
	sort(arr.begin(),arr.end(),cmp);
	
	for(int i=0;i<arr.size();i++){
		cout<<arr[i].word<<" "<<arr[i].cnt<<endl;
	}


	return 0;
}


