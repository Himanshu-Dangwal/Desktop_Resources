//Remove duplicates from an array and return an array without duplicates::

#include<bits/stdc++.h>
using namespace std;

void arrayWithoutDuplicates(vector<int> v){
	set<int> s;
	vector<int> result;
	for(int i=0;i<v.size();i++){
		if(s.find(v[i])==s.end()){
			s.insert(v[i]);
			result.push_back(v[i]);
		}	
	}
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
}

int main(){
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<;i++){
		v[i]=i+1;
	}
	arrayWithoutDuplicates(v);
	return 0;
}
