//Find the missing and repeating number::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
/*
int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int s = (n*(n+1))/2;
	int p = (n*(n+1)*(2*n + 1))/6;
	
	for(int i=0;i<n;i++){
		s -= arr[i];
		p -= arr[i] * arr[i];
	}
	
	int missing_number = (p/s + s)/2;
	int repeated_number = missing_number - s;
	
	cout<<missing_number<<" "<<repeated_number<<endl;
	return 0;
}

*/
//Approach 2::

//Using XOR
int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int xor1 = 0;
	
	for(int i=1;i<=n;i++){
		xor1 = xor1 ^ i;
		xor1 = xor1 ^ arr[i-1];
	}
	
	//Now xor1 will have missing ^ repeated 
	//Find the rightmost set bit and make 2 seaparate baskets::
//	cout<<"XOR1 = "<<xor1<<endl;
	int set_bit = xor1 & ~(xor1 - 1);
//	cout<<"Set Bit = "<<set_bit<<endl;
	int missing =  0;  //basket1
	int repeated = 0;  //basket2
	for(int i=0;i<n;i++){
		if(arr[i] & set_bit)
			missing = missing ^ arr[i];
		else
			repeated = repeated ^ arr[i];	
	}
//	cout<<missing<<" "<<repeated<<endl;
	for(int i=1;i<=n;i++){
		if(i & set_bit){
			missing = missing ^ i;
//			cout<<i<<endl;
		}
			
		else
			repeated = repeated ^ i;	
	}
	
	int counter_for_x = 0;
	
	for(int i=0;i<n;i++){
		if(arr[i] == missing){
			counter_for_x++;
			break;
		}
	}
	
	if(counter_for_x){
		cout<<"missing = "<<repeated<<"repeated = "<<missing;
	}else{
		cout<<"missing = "<<missing<<"repeated = "<<repeated;
	}
		
	return 0;	
		
	
}

// Finding the mising and repeating number using leftmost set bit::

/*
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int MxorR = 0;  //Missing xor Repeated
        for(int i=1;i<=n;i++){
            MxorR ^= nums[i-1];
            MxorR ^= i;
        }

        int x = MxorR;
        int len = 0;
        while(x > 0){
            x >>= 1;
            len++;
        }
        
        int leftmost_set_bit = 1 << (len-1);

        int bucket1 = 0,bucket2 = 0;
        for(int ele : nums){
            if(ele&leftmost_set_bit){
                bucket1 ^= ele;
            }else{
                bucket2 ^= ele;
            }
        }   

        for(int i=1;i<=n;i++){
            if(i&leftmost_set_bit){
                bucket1 ^= i;
            }else{
                bucket2 ^= i;
            }
        }

        //Traverse the array to find if bucket1 is the missing/repeating number
        bool flag = true; //bucket1 is Missing
        for(int i=0;i<n;i++){
            if(nums[i] == bucket1){
                flag = false; //Repeating
                break;
            }
        }

        vector<int> ans;
        if(flag){
            ans.push_back(bucket2);
            ans.push_back(bucket1);
        }else{
            ans.push_back(bucket1);
            ans.push_back(bucket2);
        }

        return ans;

    }
};
*/

















