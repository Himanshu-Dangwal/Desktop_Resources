//Determinant of a matrix ::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int d = 0;

int determinant(int n,vector<vector<int>> &mat){
	
	if(n==1){
		return mat[0][0];
	}
	
	if(n == 2){
		return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
	}
	
	vector<vector<int>> subMat(n-1,vector<int>(n-1,0));
	
	for(int col = 0;col < n;col++){
		int subI = 0;
		for(int i=1;i<n;i++){
			int subJ = 0;
			for(int j=0;j<n;j++){
				
				if(j == col)
					continue;
				
				subMat[subI][subJ] = mat[i][j];	
				
				subJ++;
			}
			subI++;
		}
		
		d = d + (int)(pow(-1,col)+ 0.5)*mat[0][col]*determinant(n-1,subMat); 
	}
	return d;
}


int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> mat(n,vector<int>(n,0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}

	cout<<determinant(n,mat)<<endl;
	
	return 0;
}

