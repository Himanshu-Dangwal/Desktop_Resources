#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	
	vector<bool> poss(n,false);
	poss[0] = true;
	vector<int> count(n,1);
	while(q--){
		
		int a,b;
		cin>>a>>b;
		
		a--;
		b--;
		
		if(poss[a] && count[a] > 1){
			count[a]--;
			count[b]++;
			poss[b] = true;
		}else if(poss[a] && count[a] ==  1){
			poss[a] = false;
			count[b]++;
			count[a]--;
			poss[b] = true;
		}else{
			if(count[a] > 0) count[a]--;
			count[b]++;
		}
		
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(poss[i])  cnt++;
	}
	cout<<cnt;
	return 0;
}


