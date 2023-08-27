// Linked List
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

    Node(int a){
        value = a;
        next = NULL;
    }    
};

void insertAtLast(Node* &head,int a){
     Node* k = new Node(a);
     if(head == NULL){
         head = k;
         return;
     }
     Node* temp = head;
     while(temp->next!=NULL){
         temp = temp->next;
     }
     temp->next = k;
}

void display(Node* head){
    if(head == NULL){
        cout<<"Empty"<<endl;
    }
    while(head!=NULL){
        cout<<head->value<<"->";
        head = head->next;
    }
}
int main(){
    Node* head = NULL;
    insertAtLast(head,1);
    insertAtLast(head,2);
    insertAtLast(head,3);
    display(head);
}
