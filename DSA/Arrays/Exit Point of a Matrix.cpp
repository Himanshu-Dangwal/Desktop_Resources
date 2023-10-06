//
//#include<bits/stdc++.h>
//using namespace std;
//#define endl "\n"
//#define MOD 1000000007
//typedef long long ll;
//
//int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n,m;
//	cin>>n>>m;
//	
//	int arr[n][m];
//	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cin>>arr[i][j];
//		}
//	}
//	
//	int dir = 0;
//	int i=0,j=0;
//	
//	while(i >=0 && j >=0 && i<n && j<m){
//		int move = dir%4;
//		if(move == 0){
//			//East
//			if(arr[0][0] == 1){
//				cout<<"Can't Move"<<endl;
//				return 0;
//			}
//			while(j < m && arr[i][j] == 0){
//				j++;
//			}
//			dir += 1;
//		}else if(move == 1){
//			//South
//			i++;
//			while(i < n && arr[i][j] == 0){
//				i++;
//			}
//			dir += 1;
//		}else if(move == 2){
//			//West
//			j--;
//			while(j >= 0 && arr[i][j] == 0){
//				j--;
//			}
//			dir += 1;
//		}else{
//			//North
//			i--;
//			while(i >= 0 && arr[i][j] == 0){
//				i--;
//			}
//			dir += 1;
//		}
//	}
//	cout<<endl;
////	if(i < 0 || i == n){
////		if(i < 0)
////		cout<<i<<" "<<j;
////	}else if(j < 0 || j == m){
////		cout<<i<<" "<<j;
////	}else{
////		cout<<"No exit Point"<<endl;
////	}
//
//	if(i < 0){
//		cout<<0<<" "<<j;
//	}else if(i == n){
//		cout<<n-1<<" "<<j;
//	}else if(j < 0){
//		cout<<i<<" "<<0;
//	}else if(j == m){
//		cout<<i<<" "<<m-1;
//	}else{
//		cout<<"No Exit Point";
//	}	
//
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int i=0;
	int j=0;
	int dir = 0;
	while(true){
		dir += arr[i][j];
		dir = dir%4;
		if(dir == 0){
			j++;
		}else if(dir == 1){
			i++;
		}else if(dir == 2){
			j--;
		}else if(dir == 3){
			i--;
		}
		
		if(i < 0){
			i++;
			break;
		}else if(j < 0){
			j++;
			break;
		}else if(i == n){
			i--;
			break;
		}else if(j == m){
			j--;
			break;
		}
		
	}
	cout<<i<<" "<<j<<endl;
}

