long long int merge_sort(long long arr[],long long left,long long mid,long long right){
    long long temp[right-left+1];
    long long i=left;
    long long j=mid;
    long long k = 0;
    long long int counter = 0;
    while(i < mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            counter += mid - i;
            temp[k++] = arr[j++];
        }
    }
    
    while(i < mid){
        temp[k++] = arr[i++];
    }
    
    while(j <= right){
        temp[k++] = arr[j++];
    }
    
    for(i=left,k=0;i<=right;i++,k++){
        arr[i] = temp[k];
    }
    return counter;
}

long long int merge(long long arr[],long long low,long long high){
    long long int count = 0;
    if(low < high){
        long long mid = (low + high) >> 1;
        count += merge(arr,low,mid);
        count += merge(arr,mid+1,high);
        count += merge_sort(arr,low,mid+1,high);
        return count;
    }
    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return merge(arr,0,N-1);
}

