//Calculating prefix expressions::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	string s;
	cin>>s;
	
	stack<int> st;
	
	for(int i=s.length()-1;i--){
		
		if(s[i]>='0' && s[i] <= '9'){
			st.push(s[i]-'0');
		}
		else{
			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();
			
			switch(s[i]){
				
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1,op2));			
					break;
			}
		}
	}
	
	cout<<st.top()<<endl;

	return 0;
}

