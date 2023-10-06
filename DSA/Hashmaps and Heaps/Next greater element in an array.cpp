//Next greater element on the right::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	stack<int> st;
	
	st.push(arr[n-1]);
	
	int nge[n];
	nge[n-1] = -1;
	
	for(int i= n-2;i>=0;i--){
		
		while(st.top() < arr[i]){
			st.pop();
			if(st.empty()){
				break;
			}
		}
		
		if(st.empty()){
			nge[i] = -1;
		}else{
			nge[i] = st.top();
		}
		
		st.push(arr[i]);
		
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<nge[i]<<" ";
	}

	return 0;
}

