////Print all permutations of a vector
//#include<bits/stdc++.h>
//using namespace std;
//#define endl "\n"
//#define MOD 1000000007
//typedef long long ll;
//
//vector<vector<int>> ans;
//
//void permute(vector<int> &arr,int idx){
//	if(idx == arr.size()){
//		ans.push_back(arr);
//		return;	
//	}
//	
//	for(int i=idx;i<arr.size();i++){
//		swap(arr[i],arr[idx]);
//		permute(arr,idx+1);
//		swap(arr[i],arr[idx]);
//	}
//	return;
//}
//
//int main(){
//	int n;
//	cin>>n;
//	vector<int> arr(n);
//	for(int i=0;i<n;cin>>arr[i++]);
//	
//	permute(arr,0);
//	
////	sort(arr.begin(),arr.end());
////	do{
////		ans.push_back(arr);
////	}while(next_permutation(arr.begin(),arr.end()));
//	
//	
//	for(int i=0;i<ans.size();i++){
//		for(int j=0;j<ans[i].size();j++){
//			cout<<ans[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
//}






#include<bits/stdc++.h>
using namespace std;

void permute(int arr[],int n,int idx){
	
	if(idx == n-1){
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	for(int i=idx;i<n;i++){
		swap(arr[i],arr[idx]);
		permute(arr,n,idx+1);
		swap(arr[i],arr[idx]);
	}
	
	return;
	
}


int main(){
	int n;
	cin>>n;
	
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	permute(arr,n,0);
}
















