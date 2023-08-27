#include<bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
long long findGCD(long long arr[], long long n) 
{ 
    long long result = arr[0]; 
    for (long long i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 

int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--){
        long long n;
        long long k;
        long long a[n];
        cin>>n>>k;
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        
        //if number of students==number of boxes
        
        if(k==n){
			cout<<a[0]<<endl;
        }
        
        //IF there is only 1 student
        
        if(k==1){
			cout<<a[n-1]<<endl;
        }
        
        //If number of students are less than number of boxes
        
        else
        	if(k<n){
            cout<<a[n-k]<<endl;
        	}     //If number of students > number of boxes
        	else{
                	long long sum=0;
             //Calculate the sum of all numbers and divide by total students   
                	for(long long i=0;i<n;i++){
                    	sum+=a[i];
               		 }
               		 long long ans = sum/k ;
                
              //Find GCD of the array elements
               		 long long DIv_val=findGCD(a,n);
					
            // loop to check if we can distribute - "ans" number of candies to k students
                         
           			 while(ans>DIv_val){
                         long long l=0;
                		 for(int i=0;i<n;i++){
                  			  l+=a[i]/ans;
               		 	 }
                	 	 if(l<k){
                    		ans--;
               		 	 }
                		 else{
                    		cout<<ans<<endl;
                    	 break;
               		 	 }
               		 }   
                         
                         
               		if(ans==DIv_val)
                    	cout<<ans;
                     
            }
    }
}
