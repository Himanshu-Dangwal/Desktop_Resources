//Majority Element ..Elements With Count > floor(n/3)
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int c1 = 0,c2 = 0,num1 = -1,num2 = -1;
	
	for(int ele : arr){
		if(ele == num1) c1++;
		else if(ele == num2) c2++;
		else if(c1 == 0){
			c1 = 1;
			num1 = ele;
		}else if(c2 == 0){
			c2 = 1;
			num2 = ele;
		}else{
			c1--;
			c2--;
		}
	}
	c1 = 0;
	c2 = 0;
	
	for(int i : arr){
		if(i == num1) c1++;
		else if(i == num2) c2++;
	}
	//Given the fact that atleast 1 majority element exists
	if(c1 > n/3) cout<<num1<<" ";
	if(c2 > n/3) cout<<num2;
	
	
	
	return 0;
}

