class Solution {
public:
    int minCost(int n, vector<int>& arr) {
        vector<int> nums = {0};
        for(int i = 0; i<arr.size();++i) nums.push_back(arr[i]);
        nums.push_back(n); sort(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),INT_MAX));
        for(int gap = 1; gap<nums.size();++gap){
            for(int i=0,j=gap; j<nums.size();++j,++i){
                if(gap==1) dp[i][j] = 0;
                else{
                    int cost = INT_MAX;
                    for(int k = i+1; k<j;++k){
                        cost = min(cost,dp[i][k]+dp[k][j]);
                    }
                    cost+=nums[j]-nums[i];
                    dp[i][j] = cost;
                }
            }
        }
        
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[0][dp.size()-1];
    }
};
