//Reversing a Linked List::
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node*  next;
		
		node(int val){
			data = val;
			next = NULL;
		}
};

node* head = NULL;

//void reverse(){
//	node* prevPtr = NULL;
//	node* currPtr = head;
//	node* nextPtr = NULL;
//	while(currPtr != NULL){
//		nextPtr = currPtr->next;
//		//Reversing a Link::
//		currPtr->next = prevPtr;
//		//Shifting forward all 3 Pointers::
//		prevPtr = currPtr;
//		currPtr = nextPtr;
//	}
//	//Linking head to the last element of the list::
//	head = prevPtr;
//	return;
//}

//Recursive approach to reverse a linked list::





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


    node* reverse(node* curr,int k){
        int count = 0;
        node* stay = curr;
        node* prev = NULL;
        while(count <= k && curr != NULL){
            count++;
            node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        stay->next = curr;
        return prev;
    }
    
    node* reverseBetween(int left, int right) {
        
        if(right - left == 0){
            return head;
        }
        
        if(left == 1){
            node* prev = NULL;
            node* curr = head;
            int count = 1;
            
            while(curr != NULL && count <= right){
                count++;
                node* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        
        int count = 1;
        node* curr = head;
        node* start_point = curr;
        while(count < left){
            start_point = curr;
            curr = curr->next;
            count++;
        }
        
        start_point->next = reverse(curr,right-left);
        return head;
    }


int main(){

	InsertAtHead(3);
	insertAtTail(5);
//	insertAtTail(3);
//	insertAtTail(4);
//	insertAtTail(5);
	cout<<"Normal Flow of Elements"<<endl;
	display();
	head = reverseBetween(1,2);
	cout<<"\n"<<"After Reversing"<<endl;
	display();
	return 0;
}

