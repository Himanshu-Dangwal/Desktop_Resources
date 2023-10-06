//Kth element of 2 sorted arrays::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int KthElement(vector<int> &nums1,vector<int> &nums2,int k){
	if(nums1.size() > nums2.size()){
		return KthElement(nums2,nums1);
	}
	
	int n = nums1.size();
	int m = nums2.size();
	int low = max(0,k-m);
	int high = min(n,k);
	
	while(low <= high){
		int cut1 = (low + high) >> 1;
		int cut2 = k - cut1;
		
		if(cut2 < 0){
			high = mid - 1;
			continue;
		}
		
		int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
		
		int right1 = cut1 == 0 ? INT_MAX : nums1[cut1];
		int right2 = cut2 == 0 ? INT_MAX : nums2[cut2];
		
		if(left1 <= right2 && left2 <= right1){
			return max(left1,left2);
		}
		else if(left1 > right2){
			high = cut1- 1;
		}
		else{
			low = cut1 + 1;
		}
	}
	return -1;
}


int main(){
	int n,m;
	cin>>n>>m;
	
	vector<int> nums1;
	vector<int> nums2;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		nums1.push_back(x);
	}
	
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		nums2.push_back(x);
	}
	
	int k;
	cin>>k;
	
	cout<<KthElement(nums1,nums2,k)<<endl;
	return 0;
}

