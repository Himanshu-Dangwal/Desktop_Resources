//Snakes And Ladders::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int ladder;
	cin>>ladder;
	
	vector<vector<int>> adj(100);
	
	for(int i=0;i<ladder;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	int snakes;
	cin>>snakes;

	for(int i=0;i<snakes;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
		
	queue<int> q;
	q.push(1);
	
	int moves = 0;
	
	int flag = 0;
	
	while(!q.empty()){
		
		int qlen = q.size();
		
		moves++;
		
		for(int i=0;i<qlen;i++){
			int curr_pos = q.front();
			q.pop();
			
			for(int jump=1;jump<=6;jump++){
				int new_pos = curr_pos + jump;
				if(new_pos == 100){
					flag=1;
					break;
				}
				for(auto child : adj[new_pos]){
					if(child > new_pos){
						q.push(child);
					}else if(child < new_pos){
						continue;
					}else{
						q.push(child);
					}
				}
				
				if(adj[new_pos].size() == 0 && new_pos <= 100){
					q.push(new_pos);
				}
				
			}
			
			if(flag)
				break;
					
		}
		
		if(flag)
			break;

	}
	cout<<moves<<endl;
	return 0;
}

