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
//   find_by_order(x)  Number of items strictly less than x


int main(){
	set<int> s;
	
	s.insert(40);
	set<int>::iterator it;
	int cnt = 0;
	int x = 0;
	for(it = s.begin();x < s.size();it++){
		cnt++;
		cout<<*it<<endl;
		s.insert(30);
		
		if(cnt == 4) break;
		
//		cout<<s.size()<<endl;
		x++;
	}
//	cou<<endl;

	return 0;
}

