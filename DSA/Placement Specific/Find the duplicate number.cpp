//Find the duplicate number::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int nums[n];
	for(int i=0;i<n;cin>>nums[i++]);
	
	int slow = nums[0];
	int fast = nums[0];
	
	do{
		slow = nums[slow];
		fast = nums[nums[fast]];
	}while(slow != fast);
	
	fast = nums[0];
	
	while(slow != fast){
		slow = nums[slow];
		fast = nums[fast];
	}
	
	cout<<slow<<endl;

	return 0;
}

