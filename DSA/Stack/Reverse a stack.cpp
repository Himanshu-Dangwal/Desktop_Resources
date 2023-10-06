//Reverse A Stack:::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void placeAtBottom(stack<int> &st,int x){
	if(st.empty()){
		st.push(x);
		return;
	}
	
	int a = st.top();
	st.pop();
	
	placeAtBottom(st,x);
	
	st.push(a);
}

void reverse(stack<int> &st){
	
	if(st.size() == 1){
		return;
	}
	
	int x = st.top();
	st.pop();
	
	reverse(st);
	placeAtBottom(st,x);
}

int main(){
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	
	cout<<endl;
	reverse(st);
	
	
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	
	return 0;
}

