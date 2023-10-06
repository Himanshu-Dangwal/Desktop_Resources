//Linked List
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

Node* reverseK(Node* head,int k){
	Node* prev = NULL;
	Node* curr = head;
	Node* next = NULL;
	
	int count = 0;
	
	while(curr!=NULL && count < k){
		next = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = next;
		count++;
	}
	
	if(next != NULL){
		head->next = reverseK(next,k);
	}
	
	return prev;
}


int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	Node* head = NULL;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		insert(head,x);
//		cout<<head->data;
	}
	display(head);
//	
//	cout<<endl;
//	int itemToDeltete;
//	cin>>itemToDeltete;
////	
//	delete_val(head,itemToDeltete);
//	cout<<endl;
//	display(head);
	
	cout<<"\nReversing k nodes"<<endl;
	int k=2;
	Node* newHead = reverseK(head,k);
	display(newHead);
	return 0;
}

