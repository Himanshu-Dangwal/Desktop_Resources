One of the possible solution is to first take xor of the complete array.

Now if the number of elements in array is odd:
       Then this case is easier as we can set all other numbers to (2^25 - 1) i.e all 25 bits set. Since there will be (n-1) numbers (i.e even number of terms) having their all bits set,this will result in an overall xor value as 0.And the last number then can be set as the xor value obtained from the original array.

If the number of elements are even:
      Then we can set all (n-2) elements to (2^25-1) i.e all 25 bits set in each number.Now the remaiining 2 numbers should form the xor value equivalent to the xor value of the original array.

      Now this part reduces to find 2 numbers such that their sum is maximum and they have a given xor value.So how to do it?
        
      Just take 2 numbers as 0.Now loop from the rightmost bit in the xor of original array.If the bit value is 0.Then set that bit value in both the numbers as 1.Else set that bit value in the first number as 1.


So this is the idea behind the solution to this problem.

typedef long long ll;
ll findMax(vector<int> &nums){
	int n = nums.size();
	
	ll xoro = 0;
	
	for(int x : nums) xoro ^= x;
	ll ans = 0;

	if(n%2){
		ans += (n-1)*(33554431);
		ans += xoro;
		return ans;
	}else{
		ans += (n-2)*(33554431);
		
		ll val1 = 0,val2=0;
		
		for(int i=1;i<=25;i++){
			if(((xoro>>(i-1))&1) == 0){
				//Unset
				//Set (i-1)th bit in both numbers as 1;
				
				val1 = val1 | (1<<(i-1));
				val2 = val2 | (1<<(i-1));
				
				cout<<"here"<<endl;
			}else{
				//Set
				//Set (i-1)th bit in val1 as 1;
				val1 = val1 | (1<<(i-1));
			}
		}
		return ans+val1+val2;
	}
}

