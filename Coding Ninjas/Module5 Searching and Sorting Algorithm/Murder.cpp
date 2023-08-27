/*Murder
Send Feedback
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).*/

#include<bits/stdc++.h>
using namespace std;

long long merge(long long *a,int left,int mid,int right){
	
    long long temp[right-left+1];
    int i=left,k=0;
    int j=mid;
    long long sum=0;
    while(i<mid && j<=right){
        if(a[i] < a[j]){
			sum = sum + a[i]*(right-j+1);
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<mid){
		temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
   for(int i=left,k=0;i<=right;i++,k++){
		a[i] = temp[k];
	}
    return sum;
}

long long merge_sort(long long *a,int left,int right){
    long long count = 0;
    if(right > left){
      	int middle = (left+right)/2;
        long long left_count = merge_sort(a,left,middle);
        long long right_count = merge_sort(a,middle+1,right);
        long long merge_count = merge(a,left,middle+1,right);
        return left_count + right_count + merge_count ;
    }
    return count;
}

int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<merge_sort(a,0,n-1)<<endl;
    }
}

