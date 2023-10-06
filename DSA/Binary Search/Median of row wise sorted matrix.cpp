//Median of Row Wise Sorted Matrix | Nested Binary Search
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int countSmallerThanOrEqualToMid(vector<int> &a,int mid){
	int low = 0;
	int high = a.size() - 1;
	
	while(low <= high){
		int m = (low + high) >> 1;
		if(a[m] > mid){
			high = m - 1;
		}else{
			low = m + 1;
		}
	}
	return low;
}

int findMedian(vector<vector<int>> &arr){
	int low = 1;
	int high = 1e9;
	int n = arr.size();
	int m = arr[0].size();
	while(low <= high){
		int mid = (low + high) >> 1;
		
		int count = 0;
		for(int i=0;i<n;i++){
			count += countSmallerThanOrEqualToMid(arr[i],mid);
		}
		
		if(count <= (n*m)/2){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return low;
}


int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> arr;
	
	for(int i=0;i<n;i++){
		vector<int> a;
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		arr.push_back(a);
	}
	
	cout<<findMedian(arr);

	return 0;
}

