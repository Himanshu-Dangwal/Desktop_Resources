#include<bits/stdc++.h>

int getMin(int **grid,int si,int sj,int ei,int ej,int **out){
	if(si==ei && sj==ej){
        return grid[si][sj];
    }
    if(si>ei || sj>ej){
        return MAX_INT;
    }
    
    if(grid[si][sj] <=0){
		return MAX_INT ; 
    }
    
    if(out[si]s[j] < MAX_INT){
        return out[si][sj] ;
    }
    
    int option1 = getMin(grid,si+1,sj,ei,ej,out) - grid[si][sj];
    int option2 = getMin(grid,si,sj+1,ei,ej,out) - grid[si][sj];
    
    int k = min(option1,option2);
    out[si][sj] = k;
    return k;
}


int getMinimumStrength(int** grid, int n, int m) {
	// Write your code here
    int **out = new int*[n];
    for(int i=0;i<n;i++){
		int out[i] = new int[m]; 
    	for(int j=0;j<m;j++){
			output[i][j] = MAX_INT;
        }
    }
    int a = getMin(grid,0,0,m-1,n-1,out);
    return a;
}
