//Longest Consecutive Sequence::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	unordered_set<int> s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
	}
	int lcs = 1;
	for(int i=0;i<n;i++){
		if(s.find(arr[i] - 1) == s.end()){
			int counter = 1;
			int ele = arr[i] + 1;
			while(s.find(ele) != s.end()){
				counter++;
				ele++;
			}
			lcs = max(lcs,counter);
		}
	}
	
	cout<<lcs<<endl;

	return 0;
}

//Submitted in leetcode::


/*

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
                return 0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int lcs = 1;
        
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1) == s.end()){
                int counter = 1;
                int ele = nums[i] + 1;
                while(s.find(ele) != s.end()){
                    counter++;
                    ele++;
                }
                lcs = max(lcs,counter);
            }
        }
        return lcs;
    }
};

*/

