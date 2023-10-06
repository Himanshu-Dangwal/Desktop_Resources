//Coutn of equivalent subarray alternate approach
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	set<int> s;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
//		cout<<"Inside"<<endl;
	}
//	cout<<"Here"<<endl;
//	cout<<s.size()<<endl;
//	cout<<"Now here"<<endl;
	int i = -1;
	int j = -1;
	
	int ans = 0;
	
	unordered_map<int,int> m;
	int len = n-1;
	while(true){
		bool flag1 = false;
		bool flag2 = false;
		
		while(i < len){
			//acquire till size of map becomes size of set::
			flag1 = true;
			i++;
			m[arr[i]]++;
			
			if(m.size() == s.size()){
				ans += n - i;
				break;
			}
			
		}
		
		while(j < i){
			
			flag2 = true;
		
			j++;
			m[arr[j]]--;
		 	if(m[arr[j]] == 0){
				m.erase(arr[j]);
			}
				
			if(m.size() == s.size()){
				ans += n - i;
			}else{
				break;
			}
			
			
		}
		
		
		if(!flag1 && !flag2){
			break;
		}
		
	}

	cout<<ans<<endl;
	
	return 0;
}

