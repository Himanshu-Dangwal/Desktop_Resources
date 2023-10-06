//Maximum Consecutive Ones::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	
	int i=-1;
	int j=-1;
	
	int len = n-1;
	int count = 0;
	int ans = 0;
	while(true){
		
		bool flag1 = false;
		bool flag2 = false;
		
		
		while(i < len){
			//acquire
			flag1 = true;
			i++;
			
			if(arr[i] == 0){
				count++;
			}
			
			if(count <= k){
				int pAns = i - j;
				if(pAns > ans){
					ans = pAns;
				}
			}
			
			if(count == k+1){
//				int pAns = i - j - 1;
//				if(pAns > ans){
//					ans = pAns;
//				}
				break;
			}
			
		}
		
		
		while(j < i){
			//release
			flag2 = true;
			j++;
			

			
			if(arr[j] == 0){
				count--;
			}
			
			if(count == k){
				break;
			}
		
		}
		
		if(!flag2 && !flag2){
			break;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}

