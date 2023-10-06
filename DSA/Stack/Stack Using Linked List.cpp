//Stack Using Linked list:::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Node{
	int data;
	Node* next;
	
	Node(int val){
		this->data = val;
		this->next = NULL;
	}
};

class stack{
	Node* head;
	int size;
	public:
		Stack(){
			head = NULL;
			size = 0;
		}
		
		int getSize(){
			return size;
		}
		
		bool isEmpty(){
			return size == 0;
		}
		
		void push(int element){
							
			Node* n = new Node(element);
			n->next = head;
			head = n;
			size++;
		}
		
		int pop(){
			if(head == NULL){
				cout<<"Stack is Empty"<<endl;
				return NULL;
			}
			int x = head->data;
			Node* temp = head;
			head = head->next;
			delete temp;
			size--;
			return x;
		}
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return 0;
}

