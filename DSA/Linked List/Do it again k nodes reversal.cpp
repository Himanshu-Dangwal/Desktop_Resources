//Reverse do it again::
#include<bits/stdc++.h>
using namespace std;

node* reverse(node* &head,int k){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr = NULL;
	
	int counter = 0;
	
	while(currptr != NULL && count < k){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
	}
	
	if(nextptr != NULL){
		head->next = reverse(curr->ptr,k);
	}
	return prevptr;
}

int main(){


	return 0;
}

