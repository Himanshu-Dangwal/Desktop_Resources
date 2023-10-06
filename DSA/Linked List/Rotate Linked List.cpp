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
    int getLength(ListNode* head){
        ListNode* curr = head;
        int count = 0;
        
        while(curr != NULL){
            curr = curr->next;
            count++;
        }
        
        return count;
        
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k==0) return head;
        
        int len = getLength(head);
        k = k%len;
        
        if(k == len || k == 0){
            return head;
        }
        
        int move = len - k;
        
        int count = 1;
        ListNode* curr = head;
        
        while(count < move){
            curr = curr->next;
            count++;
        }
        ListNode* temp = curr->next;
        ListNode* newHead = temp;
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        temp->next = head;
        curr->next = NULL;
        
        return newHead;
        
    }
};
