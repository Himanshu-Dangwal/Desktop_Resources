class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if(rowIndex == 0){
            return ans;
        }
        long result = 1;
        for(int j=1;j<rowIndex;j++){
            result *= (rowIndex - j + 1);
            result /= j;
            ans.push_back(result);
        }
        ans.push_back(1);
        return ans;
    }
};
