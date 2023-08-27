//Code Hussain set::
//We have gto find out MAx element of an array for each query ..After each query we have to remove the largest array of the element and replace it with half of it
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int m,n;
	cin>>n>>m;
	int a[n];
	sort(a,0,n-1);	
	int end_ptr=n-1;
	queue<ll> q;
	int count_m=0;
	while(m--){
		int current_m;
		cin>>current_m;
		ll result;
		for(;count_m<current_m;count_m++){
			if(end_ptr>=0 && (a[end_ptr]>q.front() || q.empty())){
				result=a[end_ptr];
				end_ptr--;
			}
			else{
				result=q.front();
				q.pop();
			}	
			q.push(result/2);
		}
		cout<<result<<endl;
	}
	return 0;
}
