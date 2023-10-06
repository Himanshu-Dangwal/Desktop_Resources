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
    
    ListNode* reverse(ListNode* curr,int k){
        int count = 0;
        ListNode* stay = curr;
        ListNode* prev = NULL;
        while(count <= k && curr != NULL){
            count++;
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        stay->next = curr;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(right - left == 0){
            return head;
        }
        
        if(left == 1){
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* stay = head;
            int count = 1;
            
            while(curr != NULL && count <= right){
                count++;
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(curr != NULL){
                stay->next = curr;
            }
            return prev;
        }
        
        int count = 1;
        ListNode* curr = head;
        ListNode* start_point = curr;
        while(count < left){
            start_point = curr;
            curr = curr->next;
            count++;
        }
        
        start_point->next = reverse(curr,right-left);
        return head;
    }
};
