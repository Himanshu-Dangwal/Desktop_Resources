//Next Smaller Element

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define PII pair<int,int>


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	stack<PII> st;
	
	//value vs index
	
	int nse[n];
	nse[n-1] = -1;
	
	st.push(make_pair(arr[n-1],n-1));
	
	for(int i=n-2;i>=0;i--){
		
		while(1){
			
			if(st.empty()){
				break;
			}
			
			auto x = st.top();
			if(x.first > arr[i]){
				st.pop();
			}else{
				break;
			}
			
		}
		
		if(!st.empty()){
			auto x = st.top();
			nse[i] = x.second;
		}else{
			nse[i] = -1;
		}
		
		st.push(make_pair(arr[i],i));
		
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<nse[i]<<" ";
	}
	
	return 0;
}

