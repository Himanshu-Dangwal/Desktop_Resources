//Solving the sudoku code problem
#include<bits/stdc++.h>
using namespace std;

#define N 9

bool findEmpty(int grid[N][N],int& row,int& col){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j]==0){
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}

bool isSafeInRow(int grid[N][N],int row,int i){
	for(int j=0;j<N;j++){
		if(grid[row][j]==i){
			return false;
		}
	}
	return true;
}

bool isSafeInCol(int grid[N][N],int col,int i){
	for(int j=0;j<N;j++){
		if(grid[j][col]==i){
			return false;
		}
	}
	return true;
}

bool isSafeInMatrix(int grid[N][N],int row,int col,int i){
	int rf = row-(row%3);
	int cf = col-(col%3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i+rf][j+cf]==i){
				return false;
			}
		}
	}
	return true;
}

bool isSafe(int grid[N][N],int row,int col,int i){
	if(isSafeInRow(grid,row,i) && isSafeInCol(grid,col,i) && isSafeInMatrix(grid,row,col,i)){
		return true;
	}
	return false;
}

bool solveSudoku(int grid[N][N]){
	int row,col;
	if(!findEmpty(grid,row,col)){
		return true;
	}
	
	for(int i=1;i<=9;i++){
		if(isSafe(grid,row,col,i)){
			grid[row][col]=i;
			if(solveSudoku(grid)){
				return true;
			}
			grid[row][col]=0;
		}
	}
	return false;
}

int main(){
	int N;
	cin>>N;
	int grid[N][N];
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.length();j++){
			grid[i][j]=s[j]-'0';
		}
	}
	solveSudoku(grid);
	for(int i=0;i<N;i++){
		for(int j=0;i<N;j++){
			cout<<grid[i][j];
		}
		cout<<endl;
	}
}
