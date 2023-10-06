//Nest Greater Element::
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
//	cout<<"Can i be here?"<<endl;
	stack<int> st;
//	cout<<"Before"<<endl;
	int nge[n];
	for(int i=0;i<n;i++){
		nge[i] = -1;
	}
	
	st.push(arr[n-1]);
	for(int i=n-2;i>=0;i--){
//		cout<<"Here"<<endl;
		while(st.size() != 0 && st.top() <= arr[i]){
			st.pop();
//			cout<<"Inside";
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
