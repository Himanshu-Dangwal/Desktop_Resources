#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void champagneTower(int poured, int query_row, int query_glass) {
        
        double arr[query_row + 1][query_row + 1];
        
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=query_row;j++){
                arr[i][j] = 0.0;
            }
        }
        
        arr[0][0] = poured;
        
        for(int i=0;i<query_row;i++){
            double left = 0;
            for(int j=0;j<=i;j++){
                if(arr[i][j] > 1.0){
                    left = arr[i][j] - 1.0;
                    arr[i][j] = 1.00;
                }
                arr[i+1][j] += left/2.0;
                arr[i+1][j+1] += left/2.0;
                left = 0.0;
            }
        }
        
        for(int i=0;i<=query_row;i++){
        	for(int j=0;j<=i;j++){
        		cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
//        
//        if(arr[query_row][query_glass] > 1.0){
//            return 1.00;
//        }
//        
//        return arr[query_row][query_glass];
        
}


int main(){
	int a,b,c;
	
	cin>>a>>b>>c;
	champagneTower(a,b,c);

	return 0;
}

