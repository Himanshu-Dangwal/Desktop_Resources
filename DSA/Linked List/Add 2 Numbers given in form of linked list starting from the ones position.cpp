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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        while(l1 != NULL && l2 != NULL){
            temp->next = new ListNode;
            sum = l1->val + l2->val + carry;
            temp->next->val = sum%10;
            carry = sum/10;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            temp->next = new ListNode;
            sum = l1->val + carry;
            temp->next->val = sum%10;
            carry = sum/10;
            temp = temp->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            temp->next = new ListNode;
            sum = l2->val + carry;
            temp->next->val = sum%10;
            carry = sum/10;
            temp = temp->next;
            l2 = l2->next;
        }
        
        if(carry){
            temp->next = new ListNode;
            temp->next->val = 1;
            temp = temp->next;
        }
        
        temp->next = NULL;
        return dummy->next;
    }
};
