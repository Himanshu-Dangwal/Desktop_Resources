#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mod 1000000007
typedef long long ll;



//class Solution {
//public:
//    int distinctEchoSubstrings(string text) {
//        unordered_set<string> ss;
//        int n = text.length();
//        for(int len = 1;len <= n/2;len++){\
//            int cnt = 0;
//            for(int l=0,r=len;r < n;l++,r++){
//                if(text[l] == text[r]){
//                    cnt++;
//                }else{
//                    cnt = 0;
//                }
//                
//                if(cnt == len){
//                    ss.insert(text.substr(l+1,r-l));
//                    cnt--;
//                }
//            }
//        }
//        return ss.size();
//    }
//};







int main(){
	string text;
	cin>>text;
	int n = text.length();
	ll dp[n];
	
	ll powers[n];
	int val = 31;
	powers[0] = 1;
	
	
	for(int i=1;i<n;i++){
		powers[i] = ((powers[i-1] * val)%mod + mod)%mod;
	}
	
	dp[0] = 0;
	for(int i=1;i<n;i++){
		dp[i] = (dp[i-1]*val+ (text[i]-'a'+1))%mod;
	}
	
	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	
	
	for(int i=0;i<n;i++){
		cout<<powers[i]<<" ";
	}
	cout<<endl;
	
	int l = 2,r=4;
	ll valu = (((dp[r] - dp[l])%mod*powers[r-l]%mod)+mod)%mod;
	
	cout<<valu<<endl;
	
	l=7,r=9;
	valu = (((dp[r] - dp[l])%mod*powers[r-l]%mod)+mod)%mod;
	cout<<valu;
	return 0;
}




















