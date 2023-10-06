//Introdunction To linked List::
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
		node(int val){
			this->data = val;
			this->next = NULL;
		}
};

node* head = NULL;

void insertAtTail(int val){
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

void InsertAtHead(int val){
	node* n = new node(val);
	if(head == NULL){
		head = n;
		return;
	}
	n->next = head;
	head = n;
}

void display(){
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

void delete_val(int val){
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

int main(){
	//Insertion at tail
	insertAtTail(10);
	insertAtTail(20);
	insertAtTail(30);
	display();
	cout<<endl;
	//Insertion at front
	InsertAtHead(50);
	display();
	cout<<endl;
	//Deletion at end or middle::
	delete_val(30);
	display();
	cout<<endl;
	//Deletion at front
	delete_val(50);
	display();
	return 0;
}

