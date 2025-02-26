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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head->next == NULL) return head->next;
            ListNode* last_node = head;
            for(int i = 0; i < n;i++) {
                if(last_node) last_node = last_node->next;
            }
    
            ListNode* temp = new ListNode(-1);
            temp->next = head;
            ListNode* nth_last_node = temp;
    
            while(last_node!= NULL) {
                last_node = last_node->next;
                nth_last_node = nth_last_node->next;
            }
            //at this point, nth_last_node.next is nth last node 
            nth_last_node->next =  nth_last_node->next->next; 
    
            return temp->next;  
        }
};