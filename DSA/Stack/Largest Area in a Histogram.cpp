#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define PII pair<int,int>
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
	
	int left[n];
	int right[n];
	
	right[n-1] = n;
	left[0] = -1;
	
	stack<PII> str;
	str.push({arr[n-1],n-1});
	
	for(int i=n-2;i>=0;i--){
		
		while(1){
			
			if(str.empty()){
				break;
			}else{
				auto x = str.top();
				if(x.first >= arr[i]){
					str.pop();
				}else{
					break;
				}
			}
		}
		
		if(str.empty()){
			right[i] = n;
		}else{
			auto x = str.top();
			right[i] = x.second;
		}
		
		str.push({arr[i],i});
		
	}
	
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<right[i]<<" ";
//	}
//	cout<<endl;
	
	stack<PII> stl;
	stl.push({arr[0],0});
	
	for(int i=1;i<n;i++){
		
		while(1){
			
			if(stl.empty()){
				break;
			}else{
				auto x = stl.top();
				if(x.first >= arr[i]){
					stl.pop();
				}else{
					break;
				}
			}
		}
		
		if(stl.empty()){
			left[i] = -1;
		}else{
			auto x = stl.top();
			left[i] = x.second;
		}
		
		stl.push({arr[i],i});
		
	}
	
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<left[i]<<" ";
//	}
//	cout<<endl;
	int ma = INT_MIN;
	
	for(int i=0;i<n;i++){
		ma = max(ma,(right[i]-left[i]-1)*arr[i]);	
	}
	
	cout<<endl;
	cout<<ma;
	return 0;
}

