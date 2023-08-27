///*
//Aggressive Cows Problem
//Send Feedback
//Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN 
//(0 <= xi <= 1,000,000,000).
//His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
//To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them 
//is as large as possible. What is the largest minimum distance?
//Input
//t – the number of test cases, then t test cases follows. 
//* Line 1: Two space-separated integers: N and C
//* Lines 2..N+1: Line i+1 contains an integer stall location, xi
//Output
//For each test case output one integer: the largest minimum distance.
//Sample Input :
//1
//5 3
//1
//2
//8
//4
//9
//Sample Output:
//3 
//Output details:
//FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
//resulting in a minimum distance of 3.
//*/
//
//#include<bits/stdc++.h>
//using namespace std;

bool check(long long* arr, long long d, int c, int n)
{
    int count = 1;
    long long previous = arr[0];
    for(int i=1;i<n;i++){
       if((arr[i]-previous)>=d){
            count++;
            previous=arr[i];
        }
        if(count == c)
        {
            return true;
        }
    }
    return false;
}



int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--){
        int count=1;
        int n,c;
        cin>>n>>c;

        long long arr[n];

        for(int i=0;i<n;i++){
			cin>>arr[i];
        }

        sort(arr,arr+n);
        long long ans = -1;
        long long start=0;
        long long end=arr[n-1]-arr[0];
        long long mid = 0;
        while(start<=end){
            mid=(start+end)/2;
            if(check(arr,mid,c,n)){
                start = mid+1;
                ans = mid;
            }
            else{
                end = mid -1;
            }
        }

     cout<<ans<<endl;
    }
}


//
//
//import java.util.*;
//public class Solution {
//	public static void main(String[] args) 
//    {
//		Scanner sc=new Scanner(System.in);
//        int t=sc.nextInt();
//        while(t-->0)
//        {
//            int n=sc.nextInt();
//            long cows=sc.nextLong();
//            long[] a=new long[(int)n];
//            for(int i=0;i<n;i++)
//                a[i]=sc.nextLong();
//            Arrays.sort(a);
//            long start=0;
//            long end=a[n-1]-a[0];
//            long ans=-1;
//            while(start<=end)
//            {
//                int mid=start+(end-start)/2;
//                if(binarysearch(a,n,mid,cows))
//                {
//                    ans=mid;
//                    start=mid+1;
//                }
//                else
//                    end=mid-1;
//            }  
//            System.out.print(ans+"\n");
//        }
//	}
//    public static boolean binarysearch(long[]a, int n, int long, long cows)
//    {
//        long count=1;
//        long lastPosition=a[0];
//        for(int i=1;i<n;i++)
//        {
//            if(a[i]-lastPosition>=mid)
//            {
//                count++;
//                lastPosition=a[i];
//            }
//            if(cows==count)
//                return true;
//        }
//        return false;
//    }
//
//}

