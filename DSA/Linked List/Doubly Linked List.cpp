//Doubly Linked List::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Node{
	int data;
	Node* prev;
	Node* next;
	
	Node(int val){
		data = val;
		prev = NULL;
		next = NULL;
	}
};

void insert(Node* &head,int val){
	Node* n = new Node(val);
	if(head == NULL){
		head = n;
		return;
	}
	Node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	n->prev = temp;
	temp->next = n;
}

void display(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main(){
	Node* head = NULL;
	int n,x;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x;
		insert(head,x);
	}
	cout<<endl;
	display(head);
	cout<<endl;
	display(head);
	return 0;
}

