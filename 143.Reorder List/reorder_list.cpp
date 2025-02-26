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
        void reorderList(ListNode* head) {
            deque<ListNode*> dq; 
            ListNode* start = head;
    
            while(start) {
                dq.push_back(start);
                start = start->next;
            }
            ListNode* beg = head; 
            ListNode* curr = beg; 
    
    
            while(!dq.empty()) {
                ListNode* temp = dq.front(); 
                dq.pop_front(); 
                curr->next = temp; 
                curr = curr->next;
    
                if(!dq.empty()) {
                ListNode* temp = dq.back(); 
                dq.pop_back(); 
                curr->next = temp; 
                curr = curr->next;
                }
            }  
            curr->next = NULL;     
        }
};