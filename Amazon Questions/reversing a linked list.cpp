#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update>


//   order_of_key(x)   Number of items strictrly less than x
//   find_by_order(x)  Find the kth largest element(countingg from zero)

class ListNode{
	public:
		ListNode* next;
		int val;
		
		ListNode(int val){
			this->val = val;
			this->next = NULL;
		}
};

void display(ListNode* head){
	
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

LisNode* reverse(ListNode* &head){
	if(head == NULL) return NULL;
	
	ListNode* curr = head;
	ListNode* prev = NULL;
	ListNode* next = NULL;
	
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	
	display(head);
	ListNode* rev = reverse(head);
	display(head);

	return 0;
}


