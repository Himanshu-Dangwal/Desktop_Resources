#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    vector<unordered_map<ll,ll>> ans(n);
    int count = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            ll cd =(ll)((ll)nums[i] - (ll)nums[j]);  //current difference
                
            if(ans[j][cd] > 0){
                count += ans[j][cd];
                ans[i][cd] =ans[i][cd] + ans[j][cd] + 1;
            }else{
                ans[i][cd]++;
            } 
        }
    }
    return count;
}


int main(){
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		nums.push_back(x);
	}
	
	cout<<numberOfArithmeticSlices(nums)<<endl;

	return 0;
}

