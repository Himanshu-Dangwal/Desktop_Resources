//Count of equivalent subarrays::
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
	
	ll arr[n];
	
	set<int> s;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
	}
	
	int k = s.size();
	
	
	if(k == 1){
		unordered_map<int,int> m;
		int ans = 0;
		
		int i = -1;
		int j = -1;

		n--;
		
		while(true){
			
			bool flag1 = false;
			bool flag2 = false;
			
			while(i < n){
				//acquire
				flag1 = true;
				i++;
				m[arr[i]]++;
				
				if(m.size() == 2){
					m[arr[i]]--;
					if(m[arr[i]] == 0){
						m.erase(arr[i]);
					}
					i--;
					break;
				}
				
			}
			
			
			while(j < i){
				//calculate and release
				flag2 = true;
				if(m.size() == 1){
					ans += i - j;
				}
				
				j++;
				m[arr[j]]--;
				
				if(m[arr[j]] == 0){
					m.erase(arr[j]);
				}
				
				if(m.size() == 0){
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
	
	
	unordered_map<int,int> sm;
	unordered_map<int,int> bm;
	
	n--;
	int ans = 0;
	
	int ib = -1;
	int is = -1;
	int j = -1;
	
	
	while(true){
		
		bool flag1 = false;
		bool flag2 = false;
		bool flag3 = false;
		
		//acquire in bm till characters are k::
		
		while(ib < n){
			flag1 = true;	
			ib++;
			bm[arr[ib]]++;
			
			if(bm.size() == k + 1){
				bm[arr[ib]]--;
				if(bm[arr[ib]]== 0){
					bm.erase(arr[ib]);
				}
				ib--;
				break;
			}
			
		}
		
		
		//acquire in sm till characters are k-1::
		
		while(is < ib){
			flag2 = true;
			
			is++;
			sm[arr[is]]++;
			
			if(sm.size() == k){
				sm[arr[is]]--;
				if(sm[arr[is]] == 0){
					sm.erase(arr[is]);
				}
				is--;
				break;
			}
		}
		
		//release and calculate answer::
		
		while(j < is){
			flag3 =  true;
			
			if(sm.size() == k-1 && bm.size() == k){
				ans += ib - is;
			}
			
			j++;
			sm[arr[j]]--;
			bm[arr[j]]--;
			
			if(sm[arr[j]] == 0){
				sm.erase(arr[j]);
			}
			
			if(bm[arr[j]] == 0){
				bm.erase(arr[j]);
			}
			
			if(sm.size() < k-1 || bm.size() < k){
				break;
			}
			
			
			
		}
		
		
		
		if(!flag1 && !flag2 && !flag3){
			break;
		}
		
	}
	
	cout<<ans<<endl;
	return 0;
}

