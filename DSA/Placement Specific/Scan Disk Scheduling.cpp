#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int pos;
	scanf("%d",&pos);
	
	int dir;
	scanf("%d",&dir);
	
	int min_val = 300;
	int max_val = -1;
	
	for(int i=0;i<n;i++){
		if(arr[i] < min_val)
			min_val = arr[i];
		if(arr[i] > max_val)
			max_val = arr[i];	
	}
	int ans = 0;
	if(dir == 0){
		ans += 199 - pos;
		ans += 199 - min_val;
	}else{
		ans += pos - 0 + 1;
		ans += max_val - 0;
	}
	printf("%d",ans);
	return 0;
}

