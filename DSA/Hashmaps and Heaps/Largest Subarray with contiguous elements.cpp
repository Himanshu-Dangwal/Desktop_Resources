//Length of largest subarray with contiguous elements::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		
		int max_val = arr[i];
		int min_val = arr[i];
		
		unordered_set<int> s;
		s.insert(arr[i]);
		for(int j=i+1;j<n;j++){
			
			if(s.find(arr[j]) != s.end())
				break;
				
			s.insert(arr[j]);	
			
			max_val = max(max_val,arr[j]);
			min_val = min(min_val,arr[j]);
			
			
			
			if(max_val - min_val == j-i){
				int possibleAns = j-i+1;
				if(possibleAns > ans)
					ans = possibleAns;
			}
			
		}
	}
	
	cout<<ans<<endl;
	return 0;
}

