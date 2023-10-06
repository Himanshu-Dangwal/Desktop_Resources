//Knights Probability in a chess Board::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool isValid(int ni,int nj,int n){
	
	if(ni >=0 && nj >=0 && ni<n && nj<n)
	 return true;
	 
	return false; 
	
}

int main(){
	int n;
	int k;
	cin>>n>>k;
	
	int r,c;
	cin>>r>>c;
	
	double curr[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			curr[i][j] = 0.0;
		}
	}
	
	curr[r][c] = 1.0;
	
	
	
	for(int shift = 1;shift<=k ;shift++){
		
		double next[n][n];
	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				next[i][j] = 0;
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(curr[i][j] != 0){
					int ni = 0;
					int nj = 0;
					
					ni = i-2;
					nj = j+1;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
					
					ni = i-1;
					nj = j+2;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
					
					ni = i+1;
					nj = j+2;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
					
					ni = i+2;
					nj = j+1;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
					
					ni = i+2;
					nj = j-1;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
					
					ni = i+1;
					nj = j-2;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
					
					ni = i-1;
					nj = j-2;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
					
					ni = i-2;
					nj = j-1;
					
					if(isValid(ni,nj,n)){
						next[ni][nj] += curr[i][j]/(8.0);
					}
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<next[i][j] << "           ";
			}
			cout<<endl;
		}
		
		cout<<endl;
		cout<<endl;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				curr[i][j] = next[i][j];
			}
		}
	}
	
	
	double sum = 0.0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum += curr[i][j];
		}
		cout<<endl;
	}
	
	cout<<sum<<endl;
	return 0;
}

