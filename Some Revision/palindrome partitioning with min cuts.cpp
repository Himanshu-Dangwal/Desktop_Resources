#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin>>s;
	
	int n = s.length();
	
	vector<vector<bool>> is_palindrome(n,vector<bool>(n,false));
	
	//boolean array to find palindromes::
	for(int g=1;g<n;g++){
		for(int i=0,j=g;j<n;i++,j++){
			if(g==1){
				if(s[i] == s[j]){
					is_palindrome[i][j] = true;
				}
			}else{
				if(s[i] == s[j]){
					if(is_palindrome[i+1][j-1]){
						is_palindrome[i][j] = true;
					}
				}
			}
		}
	}

	vector<vector<int>> dp(n,vector<int>(n,0));	
	
	for(int g=1;g<n;g++){
		for(int i=0,j=g;j<n;i++,j++){
			if(g==1){
				if(s[i] != s[j]){
					dp[i][j] = 1;
				}
			}else{
				if(!is_palindrome[i][j]){
					dp[i][j] = INT_MAX;
					
					for(int k=i;k<j;k++){
						int ls = dp[i][k];
						int rs = dp[k+1][j];
						
						dp[i][j] = min(dp[i][j],ls+rs);
					}
					
					dp[i][j] += 1;
				}
			}
		}
	}
	
	cout<<dp[0][n-1]<<endl;
	
	return 0;
}


