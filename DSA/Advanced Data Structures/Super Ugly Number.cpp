#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct ugly{
	int term,val,idx;
	
	ugly(int a,int b,int c){
		term = a;
		val = b;
		idx = c;
	}
};

struct compareIt{
	bool operator()(ugly const& p1,ugly const& p2){
		return p1.val > p2.val;
	}
};

void nthSuperUglyNumber(int n, vector<int>& primes) {

        
//        unordered_map<int,int> m;
//        for(int i=0;i<primes.size();i++){
//            m[primes[i]] = 1;
//        }
//        
//        int dp[n+1];
//        
//        dp[0] = 0;
//        dp[1] = 1;
//        
//        for(int i=2;i<=n;i++){
//            int mini = INT_MAX;
//            for(int j=0;j<primes.size();j++){
//                int val = primes[j] * dp[m[primes[j]]];
//                mini = min(mini,val);                                         
//            }
//                                         
//            dp[i] = mini;
//            for(int k=0;k<primes.size();k++){
//                if(primes[k] * dp[m[primes[k]]]  ==  mini){
//                    m[primes[k]]++;
//                }
//            }
//        }
//		
//		for(int i=0;i<=n;i++){
//			cout<<dp[i]<<" ";
//		}    	    

	priority_queue<ugly,vector<ugly>,compareIt> pq;
	
	
	for(int i=0;i<primes.size();i++){
		ugly temp(primes[i],primes[i],1);
		pq.push(temp);
	}
	
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i=2;i<=n;i++){
		auto curr = pq.top();
		
		dp[i] = curr.val;

		while(curr.val == dp[i]){
			pq.pop();
			ugly temp(curr.term,curr.term * dp[curr.idx+1],curr.idx + 1);
			pq.push(temp);
			curr = pq.top();
		}
		
	}
	
	for(int i=0;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	
}



int main(){
	int n;
	cin>>n;;
	
	vector<int> primes;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		primes.push_back(x);
	}
	nthSuperUglyNumber(n,primes);
	return 0;
}

