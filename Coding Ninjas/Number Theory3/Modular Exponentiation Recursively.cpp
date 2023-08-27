#include<bits/stdc++.h>
using namespace std;

void initialise(bool **visited,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    return;
}

bool check(vector<vector<char>> &board,char *ch,int i,int j,int n,int m,bool **visited){
    if(board[i][j] == 'A')
        	return true;
    bool ans = false;
	visited[i][j] = true;
    
    
    if(i-1>=0 && j-1>=0 && board[i-1][j-1] == ch[0] && !visited[i-1][j-1]){  //upper left side
        ans = ans||check(board,ch+1,i-1,j-1,n,m,visited);
    }
    if(i-1>=0 && j>=0 && board[i-1][j] == ch[0] && !visited[i-1][j]){  //upside
        ans = ans||check(board,ch+1,i-1,j,n,m,visited);
    }
     if(i-1>=0 && j+1<m && board[i-1][j+1] == ch[0] && !visited[i-1][j+1]){ //upper right
        ans = ans||check(board,ch+1,i-1,j+1,n,m,visited);
    }
     if(i>=0 && j+1<m && board[i][j+1] == ch[0] && !visited[i][j+1]){ //right
        ans = ans||check(board,ch+1,i,j+1,n,m,visited);
    }
     if(i+1<n && j+1<m && board[i+1][j+1] == ch[0] && !visited[i+1][j+1]){ //down right
        ans = ans||check(board,ch+1,i+1,j+1,n,m,visited);
    }
     if(i+1<n && j>=0 && board[i+1][j] == ch[0] && !visited[i+1][j]){ //down
        ans = ans||check(board,ch+1,i+1,j,n,m,visited);
    }
     if(i+1<n && j-1>=0 && board[i+1][j-1] == ch[0] && !visited[i+1][j-1]){ //down left
        ans = ans||check(board,ch+1,i+1,j-1,n,m,visited);
    }
     if(i>=0 && j-1>=0 && board[i][j-1] == ch[0] && !visited[i][j-1]){  //left
        ans = ans||check(board,ch+1,i,j-1,n,m,visited);
    }
    visited[i][j] = false;
    return ans ;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    char ch[] = "CODINGNINJA";
    bool **visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
    }
    initialise(visited,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'C'){
                bool ans = false;
                ans = check(board,ch+1,i,j,n,m,visited);
                if(ans)
                    return 1;
                // initialise(visited,n,m);
            }
        }
    }
    return 0;
}
