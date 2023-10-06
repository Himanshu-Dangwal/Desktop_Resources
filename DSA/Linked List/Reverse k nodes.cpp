//Reverse first k nodes of a linked list:::
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int val){
			data = val;
			next = NULL;
		}
};


void insertAtTail(node* &head,int val){
	node* n = new node(val);
	if(head == NULL){
		head = n;
		return;
	}
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
	return;
}

void InsertAtHead(node* &head,int val){
	node* n = new node(val);
	if(head == NULL){
		head = n;
		return;
	}
	n->next = head;
	head = n;
}

void display(node* &head){
	if(head == NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL";
	return;
}


void delete_val(node* &head,int val){
	node* temp = head;
	if(temp == NULL)
	{
		cout<<"List is Empty"<<endl;
		return;
	}	
	//Deletion at front::
	if(temp->data == val){
		head = temp->next;
		return;
	}
	//Deletion at middle or at end::
	while(temp->next->data != val){
		temp = temp->next;
	}
	node* temp2;
	temp2 = temp->next;
	temp->next = temp2->next;
	return;
}



node* reverseKNodes(node* &head,int k){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr = NULL;
	
	int count = 0;
	while(currptr != NULL && count<k){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
		count++;
	}
	
	if(currptr != NULL){
		head->next = reverseKNodes(currptr,k);
	}
	return prevptr;
}

int main(){
	node* head = NULL;
	InsertAtHead(head,6);
	InsertAtHead(head,5);
	InsertAtHead(head,4);
	InsertAtHead(head,3);
	InsertAtHead(head,2);
	InsertAtHead(head,1);
	display(head);
	cout<<endl;
	node* newHead = reverseKNodes(head,2);
	display(newHead);

	return 0;
}

