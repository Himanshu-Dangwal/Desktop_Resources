#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool isValid(int x,int y,int n){
	
	if(x < 0  ||  y < 0  || x >= n || y >= n)
		return false;
		
	return true;	
	
}

int minMoves(int** arr,int si,int sj,int ei,int ej,int** visited,int n){
	
	int dirX[] = {-2,-1,+1,+2,+2,+1,-1,-2};
	int dirY[] = {+1,+2,+2,+1,-1,-2,-2,-1};
	
	queue<pair<int,int>> q;
	q.push(make_pair(si,sj));
	visited[si][sj] = 1;
	
	while(!q.empty()){
		
		auto x = q.front();
		
		int xi = x.first;
		int yi = x.second;
		q.pop();
		
		cout<<"xi = "<<xi <<" yi = "<<yi<<endl;
		
		for(int i=0;i<8;i++){
			int nx = xi + dirX[i];
			int ny = yi + dirY[i];
			
			if(isValid(nx,ny,n) && visited[nx][ny] == 0){
				arr[nx][ny]  =  arr[xi][yi] + 1;
				visited[nx][ny] = 1;
				q.push(make_pair(nx,ny));
//				cout<<nx<<" "<<ny<<" ";
//				cout<<endl;
			}
			
			if(nx == ei && ny == ej){
//				for(int i=0;i<n;i++){
//					for(int j=0;j<n;j++){
//						cout<<arr[i]<<" ";
//					}
//					cout<<endl;
//				}
				return arr[nx][ny];
			}
				
		}
	}
	return NULL;
}

int main(){
	
	int n;
	cin>>n;
	
	int kpx,kpy;
	cin>>kpx>>kpy;
	
	int ei,ej;
	cin>>ei>>ej;
	
	int** arr = new int*[n];
	for(int i=0;i<n;i++){
		arr[i] = new int[n];
		for(int j=0;j<n;j++){
			arr[i][j] = 0;
		}
	}
	
	int** visited = new int*[n];
	for(int i=0;i<n;i++){
		visited[i] = new int[n];
		for(int j=0;j<n;j++){
			visited[i][j] = 0;
		}
	}
	
	cout<<minMoves(arr,kpx,kpy,ei,ej,visited,n)<<endl;
	
	return 0;
}

