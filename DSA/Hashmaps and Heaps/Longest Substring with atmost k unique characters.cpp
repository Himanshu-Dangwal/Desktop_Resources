//Longest Substring with Atmost k unique characters::

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
	
	unordered_map<char,int> m;
	
	int i = -1;
	int j = -1;
	
	int ans = 0;
	
	int n = s.length();
	
// 	cout<<n<<endl;
	
	n--;
	
	
	while(true){
		bool flag1 = false;
		bool flag2 = false;
		
		while(i < n){
			//Acquire
			flag1 = true;
			

			
			i++;
			m[s[i]]++;
			
			if(m.size() > k){
				break;
			}
			
			int pAns = i - j;
			if(pAns > ans){
				ans = pAns;
			}
			
		}
		
		while(j < i){
			//Release
			flag2 = true;
			
			j++;
			m[s[j]]--;
			
			if(m[s[j]] == 0){
				m.erase(s[j]);
			}
			
			if(m.size() == k){
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

