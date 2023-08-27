#include<bits/stdc++.h>
using namespace std;

int main(){
	unordered_set<int> s = {3};
	if(s.find(4)!=s.end()){
		cout<<"Foubd";
	}
	else{
		cout<<"Not found";
	}
	return 0;
}
