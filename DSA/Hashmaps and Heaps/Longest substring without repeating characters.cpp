//Longest Substring Without Repeating Characters::
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
	
	unordered_map<char,int> m;
	
	int ans = 0;
	
	int i = -1;
	int j = -1;
	
	while(true){
		bool flag1 = false;
		bool flag2 = false;
		
		//acquire
		int n = s.length();
		n--;

		while(i < n){
			flag1 = true;
			i++;
			
			m[s[i]]++;
			
			if(m[s[i]] > 1){
				break;
			}else{
				int pAns = i-j;
				if(ans < pAns)
					ans = pAns;
			}
			
		}
		
		
		//calculate and release
		while(j < i){
			flag2 = true;
			
			j++;
			m[s[j]]--;
			
			if(m[s[j]] == 1)
				break;
			
		}
		
		
		if(flag1 == false && flag2 == false){
			break;
		}
		
	}
	
	cout<<ans<<endl;

	return 0;
}

