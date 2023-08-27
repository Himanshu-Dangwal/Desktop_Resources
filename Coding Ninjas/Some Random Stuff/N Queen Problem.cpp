
#include <bits/stdc++.h>

using namespace std;

//int board[4][4];

bool isPossible(int n,int row,int col,int** board){

// Same Column
  for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
      return false;
    }
  }
//Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }

  // Upper Right Diagonal

  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }

  return true;
}
void nQueenHelper(int n,int row,int** board){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << board[i][j] << " ";
      }
      cout<<endl;
    }
    cout<<endl;
    return;

  }

  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++){

    if(isPossible(n,row,j,board)){
      board[row][j] = 1;
      nQueenHelper(n,row+1,board);
      board[row][j] = 0;
    }
  }
  return;

}
void placeNQueens(int n,int ** board){

//  memset(board,0,4*4*sizeof(int));

  nQueenHelper(n,0,board);

}
int main(){

  int** board = new int*[4];
  for(int i=0;i<4;i++){
  	board[i] = new int[4];
	  for(int j=0;j<4;j++){
		board[i][j] = 0;
	  }
  }
  placeNQueens(4,board);
  return 0;
}
