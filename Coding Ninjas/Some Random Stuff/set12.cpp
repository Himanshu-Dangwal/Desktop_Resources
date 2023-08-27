#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v={1,2,3,3,4,5};
	set<int> s;
	set<int>::iterator it;
	for(int i=0;i<v.size();i++){
		s.insert(v[i]);
	}
	for(it=s.begin();it!=s.end();it++){
		cout<<*it;
	}
	
}

//Code to remove duplicates from an array:::::
