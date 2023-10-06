//Reversing A Linked list
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


struct Node{
	int data;
	Node* next;
	
	Node(int val){
		data = val;
		next = NULL;
	}
};

void insert(Node* &head,int data){
	if(head == NULL){
		head = new Node(data);
		return;
	}
	Node *n = new Node(data);
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}	
	temp->next = n;
	return;
}

void delete_val(Node* &head,int item){
	if(head->data == item){
		Node* temp = head;
		head = head->next;
		free(temp);
		return;
	}
	
	Node* temp = head;
	while(temp->next->data != item){
		temp = temp->next;
	}
	
	Node* temp2;
	temp2 = temp->next;
	temp->next = temp->next->next;
	delete temp2;
}

void display(Node* head){
	if(head == NULL)
		return;
//	cout<<head->data<<" ";
//	display(head->next);
	Node* temp = head;
	while(temp->next != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
	return;
}
/*
Node* reverse(Node *&head){
	Node* curr = head;
	Node* next = NULL;
	Node* prev = NULL;
	
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = next;
	}
	head = prev;
	return prev;
}
*/

void reverse(Node *&head){
	Node* curr = head;
	Node* next = NULL;
	Node* prev = NULL;
	
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = next;
	}
	head = prev;
}

Node* reverseRecursively(Node* head){
	if(head == NULL || head->next == NULL)
		return head;
	
	Node* newHead = reverseRecursively(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;	
}


int main(){

	Node* head = NULL;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		insert(head,x);
	}
	display(head);
	
	cout<<"\nInsert Item to be deleted::\n";
	int itemToDeltete;
	cin>>itemToDeltete;

	delete_val(head,itemToDeltete);
	cout<<endl;
	display(head);
	
	cout<<"\nReversing the list"<<endl;
	
//	Node* newHead = reverse(head);
//	reverse(head);

//	Node* newHead = reverseRecursively(head);
//	display(newHead);
	Node* newHead = reverseRecursively(head);
	display(newHead);
	
	
	cout<<endl;
//	display(newHead);
	return 0;
}
