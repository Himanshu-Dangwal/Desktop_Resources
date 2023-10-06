//Next greater Element by preserving the indices ::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	stack<int> st;
	int result[n];
	
	for(int i=n-1;i>=0;i--){
		
		if(!st.empty()){
			while(!st.empty() && st.top() <= arr[i] ){
				st.pop();
			}
		}
		
		result[i] = st.empty() ? -1 : st.top();
		st.push(arr[i]); 
	
	}

	for(int i=0;i<n;i++){
		cout<<result[i]<<" ";
	}
	
	return 0;
}

