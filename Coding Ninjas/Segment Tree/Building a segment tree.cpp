 //Building a segment treee:::
#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeIndex){
	if(start == end){
		tree[treeIndex] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr,tree,start,mid,2*treeIndex);
	buildTree(arr,tree,mid+1,end,2*treeIndex+1);
	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
	return ; 
}

//Update on a Segment Tree:::

void update(int *arr,int *tree,int start,int end,int treeIndex,int index,int value){
	if(start == end){
		tree[treeIndex] = value;
		arr[index] = value;
		return;
	}
	int mid = (start + end)/2;
	if(index > mid){
		update(arr,tree,mid+1,end,2*treeIndex+1,index,value);
	}else{
		update(arr,tree,start,mid,2*treeIndex,index,value);
	}
	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
	return;
}

int query(int *tree,int start,int end,int treeNode,int left ,int right){
	//There will be 3 cases:::
	// 1: Completely Outside return 0;
	if((start > right && end > right)||(start<left && end<left)){
		return 0;
	}
	// 2: Completely Inside:::
	if(start>=left && end<=right){
		return tree[treeNode];
	}
	// 3: Partially inside And partially oustside:::
	int mid = (start+end)/2;
	int ans1 = query(tree,start,mid,2*treeNode,left,right);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
	return ans1+ans2;
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int *tree = new int[2*n];
	buildTree(arr,tree,0,n-1,1);
	
	for(int i=1;i<2*n;i++){
		cout<<tree[i]<<endl;
	}
	cout<<endl;
	update(arr,tree,0,n-1,1,2,10);
	cout<<"Tree After Updating is"<<endl;
	for(int i=1;i<2*n;i++){
		cout<<tree[i]<<endl;
	}
	cout<<endl;
	cout<<"Query 1 is from 2 to 6"<<endl;
	int ans = query(tree,0,n-1,1,2,6);
	cout<<ans;
	return 0;
}
