#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int merge(int arr[],int left,int mid,int right){
	int i=left,j=mid,k=0;
	int temp[right - left + 1];
	int count = 0;
	while(i < mid && j <= right){
		if(arr[i] >  arr[j]){
			int l = i,h = mid-1;
			while(l <= h){
				int m = (l + h) >> 1;
				if(arr[m] > 2 * arr[j]){
					h = m - 1;
				}else{
					l = m + 1;
				}
			}
			if(l != mid){
				count += mid - l; 
			}
			temp[k++] = arr[j++];	
		}else{
			temp[k++] = arr[i++];
		}
	}
	
	while(i < mid){
		temp[k++] = arr[i++];
	}
	
	while(j <= right){
		temp[k++] = arr[j++];
	}
	
	for(int i=left,k=0;i<=right;i++,k++){
		arr[i] = temp[k];
	}
	return count;
}

int merge_sort(int arr[],int left,int right){
	int count = 0;
	
	if(left < right){
		int mid = (left + right) >> 1;
		int lc = merge_sort(arr,left,mid);
		int rc = merge_sort(arr,mid + 1,right);
		int mc = merge(arr,left,mid+1,right);
		
		return lc + rc + mc;

	}
	return count;
}

int getReversePairs(int arr[],int n){
	return merge_sort(arr,0,n-1);
}

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<getReversePairs(arr,n)<endl;

	return 0;
}

