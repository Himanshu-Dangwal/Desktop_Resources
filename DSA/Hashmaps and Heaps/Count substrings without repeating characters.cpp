//Count Substrings without repeating characters::
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
	
	int i=-1;
	int j=-1;
	
	unordered_map<char,int> m;
	
	int n = s.length();
	int ans = 0;
	n--;
	
	while(true){
		
		bool flag1 = false;
		bool flag2 = false;
		
		
		while(i < n){
			
			//acquire
			
			flag1 = true;
			
			i++;
			m[s[i]]++;
			
			if(m[s[i]] == 2){
			    break;
			}else{
			    ans += i - j;
			}
			
		}
		
		
		while(j < i){
			
			flag2 = true;
			
			j++;
			m[s[j]]--;
			
			//release
			if(m[s[j]] == 1){
				ans += i - j;
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

