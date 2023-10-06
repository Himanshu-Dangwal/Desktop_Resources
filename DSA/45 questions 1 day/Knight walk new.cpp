//Knight walk khud se::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
typedef tuple<int,int,int> type;

struct cell{
	int x,y,data;
	
	cell(int x,int y,int data){
		this->x = x;
		this->y = y;
		this->data = data;
	}
};

bool isInside(int x, int y, int N)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N)
		return true;
	return false;
}

int min_moves(int  knightPos[],int targetPos[],int n){
	
	int visited[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			visited[i][j] = 0;
		}
	}
	
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	
	queue<cell> q;
	cell t(knightPos[0],knightPos[1],0);
	
	q.push(t);
	
	int x,y;
	
	while(!q.empty()){
		cell k = q.front();
		q.pop();
		
		if(k.x == targetPos[0] && k.y == targetPos[1]){
			return k.data;
		}
		
		for(int i=0;i<8;i++){
			x = k.x + dx[i];
			y = k.y + dy[i];
			
			if(isInside(x,y,n) && !visited[x][y]){
				visited[x][y] = true;
				q.push({x,y,k.data+1});
			}
		}
	}
}


int main(){
	
	cout<<"Input value of n"<<endl;
	
	int n;
	cin>>n;

	int knightPos[2];
	int targetPos[2];
	
	cin>>knightPos[0]>>knightPos[1]>>targetPos[0]>>targetPos[1];
	
	cout<<min_moves(knightPos,targetPos,n);

	return 0;
}

