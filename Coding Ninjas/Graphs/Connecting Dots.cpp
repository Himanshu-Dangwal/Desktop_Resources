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

bool check(vector<vector<char>> &board,char ch,int i,int j,int n,int m,bool **visited,int len,int sv,int ev){
    if(len>=4 && ((i==sv+1 && j==ev)||(i==sv &&j==ev-1)||(i==sv-1&&j==ev)||(i==sv && j==ev+1)))
        	return true;
    bool ans = false;
	visited[i][j] = true;

    if(i-1>=0 && j>=0 && board[i-1][j] == ch && !visited[i-1][j]){  //upside
        ans = ans||check(board,ch,i-1,j,n,m,visited,len+1,sv,ev);
        // return ans;
    }
 
    if(i>=0 && j+1<m && board[i][j+1] == ch && !visited[i][j+1]){ //right
        ans = ans||check(board,ch,i,j+1,n,m,visited,len+1,sv,ev);
        // return ans;
    }
   
    if(i+1<n && j>=0 && board[i+1][j] == ch && !visited[i+1][j]){ //down
        ans = ans||check(board,ch,i+1,j,n,m,visited,len+1,sv,ev);
        // return ans;
    }
   
    if(i>=0 && j-1>=0 && board[i][j-1] == ch && !visited[i][j-1]){  //left
        ans = ans||check(board,ch,i,j-1,n,m,visited,len+1,sv,ev);
        // return ans;
    }
    visited[i][j] = false;
    return ans ;
}

int hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    char ch;
    bool **visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
    }
    int len = 0;
    initialise(visited,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // if(board[i][j] == 'C'){
            //     bool ans = false;
            //     ans = check(board,ch+1,i,j,n,m,visited);
        	ch = board[i][j];
            bool ans = false;
            ans = check(board,ch,i,j,n,m,visited,len+1,i,j);
            if(ans)
                return 1;
            // initialise(visited,n,m);
        }
    }
    return 0;
}
    



// #include<bits/stdc++.h>
// using namespace std;
// int code(vector<vector<char>> &board, char str, int n, int m, int start, int end, int i, int j, bool** visited, int x){
//     visited[i][j] = true;
//     if((i==start+1 && j==end)||(i==start && j==end-1)||(i==start && j==end+1)||(i==start-1 && j==end)){
//         if(x >= 4 && board[i][j] == str) 
//             return true;
//     }
//     if(i>=0 && j-1>=0){
//         if(board[i][j-1] == str){
//             if(visited[i][j-1] == false){
//                 bool a = code(board, str, n, m, start, end, i, j-1, visited, x+1);
//                 if(a == true) 
//                     return true;
//             }
//         }
//     }
//     if(i+1<n && j>=0){
//         if(board[i+1][j]==str){
//             if(visited[i+1][j]==false){
//                 int b = code(board, str, n, m, start, end, i+1, j, visited, x+1);
//                 if(b==true) 
//                     return true;
//             }
//         }
//     }
//     if(i>=0 && j+1<m){
//         if(board[i][j+1]==str){
//             if(visited[i][j+1]==false){
//                 int c = code(board, str, n, m, start, end, i, j+1, visited, x+1);
//                 if(c==true) 
//                     return true;
//             }
//         }
//     }
//     if(i-1>=0 && j>=0){
//         if(board[i-1][j]==str){
//             if(visited[i-1][j]==false){
//                 int d = code(board, str, n, m, start, end, i-1, j, visited, x+1);
//                 if(d==true) 
//                     return true;
//             }
//         }
//     }
//     visited[i][j] = false;
//     return false;
// }

// int hasCycle(vector<vector<char>> &board, int n, int m){
//     ios_base:: sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     int size = s.length();
//     bool** visited = new bool*[n];
//     for(int i=0;i<n;i++){
//         visited[i] = new bool[m];
//         for(int j=0;j<m;j++){
//             visited[i][j] = false;
//         }
//     }
//     while(size > 0){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(board[i][j] == s[0]){
//                     int x = 1;
//                     int ans = code(board, s[0], n, m, i, j, i, j, visited, x);
//                     if(ans == 1) 
//                         return 1;
//                 }
//             }
//         }
//         s = s.substr(1);
//         size = size-1;
//         for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             visited[i][j] = false;
//         }
//     }
//     }
//     return 0;
// }
