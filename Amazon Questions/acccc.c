


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)
#include<stdio.h>
#include<stdlib.h>
int main(){
//	float i = 9.2;
//	int j = i%2 * 5/2;
//	printf("%d",j);
	
//	if(i == 9.2){
//		printf("Yes");
//	}
//
//	char num = '\010';
//	printf("%d",num);
//	int x = 1,y=10;
//	
//	int *a = &x;
//	int *b = &y;
//
//	printf("%d",*a * *b);
//	
//	int *c;
//	c = 22;

//	int n,m;
//	int x = scanf("%d %d",&n,&m);
//	printf("%d",x);

//	int arr1[] = {11,22,33,44,55}, arr2[5],*p,i=1;;
//	p = arr2;
//	
//	for(i=0;i<5;i++){
//		*p = (*arr1)++;
//		p++;
//	}
//	
//	for(i=0;i<5;i++){
//		printf("%d ",arr2[i]);
//	}

//	int ans = floor(log2(6)) + 1;
//	printf("%d",ans);

	int *change(int b[]){
		int i;
		for(i=0;i<3;i++){
			b[i]++;
			return (b);
		}
	}
	
	int main(){
		int a[] = {10,20,30},*p,i=1;
		p = (int *)malloc(3 * sizeof(int));
		p = change(a);
		for(i=0;i<3;i++){
			printf("%d ",*(p+i));
		}
	}
	return 0;
}


