//Check for Plaindromic Linked list O(1) space and O(n) time
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	

	return 0;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* find(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid = find(head);
        mid->next = reverse(mid->next);
        
        ListNode* curr = head;
        ListNode* second = mid->next;
        
        bool flag = true;
        while(second != NULL){
            if(curr->val != second->val){
                flag = false;
                break;
            }
            curr = curr->next;
            second = second->next;
        }
        
        mid->next = reverse(mid->next);
        if(flag)
            return true;
        return false;
        
    }
};
