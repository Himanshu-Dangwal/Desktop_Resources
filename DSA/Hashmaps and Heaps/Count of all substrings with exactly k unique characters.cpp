#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin>>s;
	
	int k;
	cin>>k;
	
	if(k == 1){
		unordered_map<char,int> m;
		int ans = 0;
		
		int i = -1;
		int j = -1;
		int n = s.length();
		n--;
		
		while(true){
			
			bool flag1 = false;
			bool flag2 = false;
			
			while(i < n){
				//acquire
				flag1 = true;
				i++;
				m[s[i]]++;
				
				if(m.size() == 2){
					m[s[i]]--;
					if(m[s[i]] == 0){
						m.erase(s[i]);
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
				m[s[j]]--;
				
				if(m[s[j]] == 0){
					m.erase(s[j]);
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
	
	
	unordered_map<char,int> sm;
	unordered_map<char,int> bm;
	
	int n = s.length();
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
			bm[s[ib]]++;
			
			if(bm.size() == k + 1){
				bm[s[ib]]--;
				if(bm[s[ib]]== 0){
					bm.erase(s[ib]);
				}
				ib--;
				break;
			}
			
		}
		
		
		//acquire in sm till characters are k-1::
		
		while(is < ib){
			flag2 = true;
			
			is++;
			sm[s[is]]++;
			
			if(sm.size() == k){
				sm[s[is]]--;
				if(sm[s[is]] == 0){
					sm.erase(s[is]);
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
			sm[s[j]]--;
			bm[s[j]]--;
			
			if(sm[s[j]] == 0){
				sm.erase(s[j]);
			}
			
			if(bm[s[j]] == 0){
				bm.erase(s[j]);
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

