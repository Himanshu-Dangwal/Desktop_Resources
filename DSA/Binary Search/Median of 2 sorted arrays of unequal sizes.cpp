#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

double findMedian(vector<int> &nums1,vector<int> &nums2){
	if(nums1.size() > nums2.size()){
		return findMedian(nums2,nums1);
	}
	
	int low = 0;
	int high = nums1.size();
	
	int n1 = nums1.size();
	int n2 = nums2.size();
	
	while(low <= high){
		int mid = (low + high) >> 1;
		
		int cut1 = mid;
		int cut2 = (n1 + n2 + 1)/2 - cut1;
		int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
		
		int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
		int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
		
		if(left1 <= right2 && left2 <= right1){
			if((n1+n2)%2 == 0){
				return (max(left1,left2) + min(right1,right2))/2;
			}else{
				return (double)max(left1,left2);
			}
		}else if(left1 > right2){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return 0.0;
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
	
//	for(int i=0;i<n;i++){
//		cout<<nums1[i]<<" ";
//	}
//	cout<<endl;
//	
//	for(int i=0;i<m;i++){
//		cout<<nums2[i]<<" ";
//	}
//	cout<<endl;
	
	cout<<findMedian(nums1,nums2);
	return 0;
}

