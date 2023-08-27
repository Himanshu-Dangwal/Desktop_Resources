#include<bits/stdc++.h>
//BEst time complexity approach using merge sort::
long long merge(long long arr[],int left,int mid,int right){

	int i=left,j=mid,k=0;

	long long temp[right-left+1];
	long long count = 0;
	while(i<mid && j<=right){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			count += mid - i;
		}
	}
	while(i<mid){
		temp[k++] = arr[i++];
	}
	while(j<=right){
		temp[k++] = arr[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++){
		arr[i] = temp[k];
	}
	return count;
}
long long merge_sort(long long arr[],int left,int right){

	long long count = 0;
	if(right > left){
		int mid = (left + right)/2;

		long long countLeft = merge_sort(arr,left,mid);
		long long countRight = merge_sort(arr,mid+1,right);
		long long myCount = merge(arr,left,mid+1,right);

		return myCount + countLeft + countRight;
	}
	return count;

}
long long getInversions(long long arr[], int n)
{
	long long ans = merge_sort(arr,0,n-1);
	return ans;
}



/*
1>Break the arra into 2 half::
2>Sort the 2 half seaparately but first calculate the indivisual inversion counts::
3>Merge the 2 halfs but while merging just increment the count::

Final_count=leftCOunt+rightCount+MergeCount*/

/*
    Approach 1::
    unordered_map<long long,long long> m;
    for(long long i=0;i<n;i++){
        m[arr[i]]=i;
    }
    sort(arr,arr+n);
    long long j;
    long long count=0;
    for(int i=0;i<n;i++){
        j=i+1;
        while(j<n){
			if(m[arr[j]]<i){
                count++;
            }
        }
    }
    return count;
*/
