#include<bits/stdc++.h>
using namespace std;
#define long long int

signed main(){
	int t;
	cin>>t;
	while(t--){
		int N,M;              //N=Number of time intervals       M= Number of peoples entering:::
		cin>>N>>M;
		int start,end;
		vector<pair<int,int>> intervals;
		for(int i=0;i<N;i++){
			cin>>start>>end;
			intervals.push_back(make_pair(start,end));
		}
		sort(intervals.begin(),intervals.end());
		while(M--){
			int current_time;
			cin>>current_time;
			int position = lower_bound(intervals.begin(),intervals.end(),make_pair(current_time,0))-intervals.begin();
			if(position == 0){
				int ans=intervals[0].first - current_time;
				cout<<ans<<endl;
			}
			else{
				int ans=-1;
				if(intervals[position-1].second > current_time){
					ans=0;
				}
				else
					if(position < intervals.size()){
						ans = intervals[position].first - current_time;
					}
				cout<<ans<<endl;	
			}
		}		
	}
}
