//Detection And Removal Of cycle in Linekd list
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


void makeCycle(Node* &head,int pos){
	
	int curr = 0;
	Node* temp = head;
	Node* cycleNode = NULL;
	while(temp->next != NULL){
		curr++;
		if(curr == pos){
			cycleNode = temp;
		}
		temp = temp->next;
	}
	
	temp->next = cycleNode;
}

bool checkCycle(Node* head){
	Node* fast;
	Node* slow;
	
	fast = head;
	slow = head;
	
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast){
			return true;
		}
	}
	return false;
}

void removeCycle(Node* &head){
	Node* fast = head;
	Node* slow = head;
	
	do{
		slow = slow->next;
		fast = fast->next->next;
	}while(slow != fast);
	
	fast = head;
	
	while(fast->next != slow->next){
		fast = fast->next;
		slow = slow->next;
	}
	
	slow->next = NULL;
}

int main(){

	Node* head = NULL;
	int n,x;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x;
		insert(head,x);		
	}
	
	makeCycle(head,3);
	
	bool isCycle = checkCycle(head);
	if(isCycle)
		cout<<"true"<<endl;
	else{
		cout<<"false"<<endl;
	}	
	
	if(isCycle){
		removeCycle(head);
		display(head);
	}
	return 0;
}





























