////Climb stairs with variable jumps::
////Total ways::
#include <bits/stdc++.h>
using namespace std;

int countStairs(vector<int> &arr)
{
	int n = arr.size();
	int dp[n + 1];

	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		int cur = arr[i];

		dp[i] = 0;
		for (int j = 1; j <= cur && i + j <= n; j++)
		{
			dp[i] += dp[i + j];
		}
	}

	return dp[0];
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << countStairs(arr);

	return 0;
}
// void swap(int *a,int *b){
// 	int t = *a;
// 	*a = *b;
// 	*b = t;
// 	return;
// }

// int partition(int arr[],int low,int high){
// 	int i = low-1;
// 	int pivot = arr[high];
// 	for(int j=low;j<high;j++){
// 		if(arr[j]<pivot){
// 			i++;
// 			swap(&arr[j],&arr[i]);
// 		}
// 	}
// 	swap(&arr[i+1],&arr[high]);
// 	return (i+1);
// }

// void quick_sort(int arr[],int low,int high){
// 	if(low<high){
// 		int pi = partition(arr,low,high);
// 		quick_sort(arr,low,pi-1);
// 		quick_sort(arr,pi+1,high);
// 	}
// 	return;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n;
// 	cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;cin>>arr[i++]);

// 	quick_sort(arr,0,n-1);
// 	for(int i=0;i<n;i++){
// 		cout<<arr[i]<<" ";
// 	}
// 	return 0;
// }
