//Find Intersection point of 2 Linked List:::
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

int getLength(Node* n){
	int len = 1;
	while(n != NULL){
		len++;
		n = n->next;
	}
	return len;
}

int find_intersection(Node* n1,Node* n2){
	int len1 = getLength(n1);
	int len2 = getLength(n2);
	
	int k;
	Node* temp1;  //For Linked List Having Greater length
	Node* temp2;  //For Other Linked List
	if(len1 > len2){
		temp1 = n1;
		temp2 = n2;
		k = len1 - len2;	
	}else{
		temp1 = n2;
		temp2 = n1;
		k = len2 - len2;
	}
	if(k==0)
		return n1->data;
	int curr = 0;
	while(curr != k){
		temp1 = temp1->next;
		curr++;
	}	
	
	while(temp1->next != temp2->next){
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return temp1->next->data;
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
	
	cout<<endl;
	int itemToDeltete;
	cin>>itemToDeltete;
//	
	delete_val(head,itemToDeltete);
	cout<<endl;
	display(head);
	return 0;
}

