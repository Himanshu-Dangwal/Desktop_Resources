//Doubly Linked List::
//Append Last K nodes Of  A Linked list::
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

int getLength(Node* head){
	Node* temp = head;
	int l = 0;
	while(temp != NULL){
		l++;
		temp = temp->next;
	}
	return l;
}

Node* append(Node* &head,int k){
	int len = getLength(head);
	k = k%len;
	Node* newHead;
	Node* newTail;
	Node* tail = head;
	int counter =1;
	
	while(tail->next != NULL){
		if(len-k == counter){
			newTail = tail;
		}
		if(len-k+1 == counter){
			newHead = tail;
		}
		tail = tail->next;
		counter++;
	}
	tail->next = head;
	head->prev = tail;
	
	newTail->next = NULL;
	
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
	cout<<endl;
	display(head);
	cout<<endl;
//	display(head);

	Node* newHead = append(head,3);
	display(newHead);
	return 0;
}

