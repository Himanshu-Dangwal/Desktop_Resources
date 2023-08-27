#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solution[20][20];

bool possible(int row,int column,int maze[][20],int n){
    if(row<0 || row==n || column<0 || column==n){
        return false;
    }
    if(maze[row][column]==1 && solution[row][column]==0){
        return true;
    }
    return false;
}

void ratN(int maze[][20],int n,int row,int column){
    if(row<0 || row==n || column<0 || column==n){
        return;
    }
    if(solution[row][column]==1){
    	return;
	}
    if(row==n-1 && column==n-1){
    	solution[row][column]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solution[i][j];
            }
        }
    cout<<endl;
    solution[row][column]=0;
    }
    if(possible(row,column,maze,n)){
        solution[row][column]=1;
        ratN(maze,n,row,column+1);
        ratN(maze,n,row-1,column);
        ratN(maze,n,row+1,column);
        ratN(maze,n,row,column-1);
        solution[row][column]=0;
    }
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
	memset(solution,0,20*20*sizeof(int));
	ratN(maze,n,0,0);
}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}



