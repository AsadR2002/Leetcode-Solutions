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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* dummy= new ListNode(-1); 
            ListNode* prev = dummy; 
            while(list1 && list2) {
                if(list1->val < list2->val){
                    prev->next = list1; 
                    list1 = list1->next;
                }
                else {
                    prev->next = list2; 
                    list2 = list2->next;
                }
                prev = prev->next; 
            }
            if(list1) prev->next = list1;
            if(list2) prev->next = list2;
    
            return dummy->next;  
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode* most_recent = new ListNode(-1);
            if(lists.size() == 0) return most_recent->next; 
    
            if(lists.size() < 2) return lists[0];
    
            most_recent->next = lists[0];
    
            for(int i = 1; i < lists.size(); i++){
                most_recent->next = mergeTwoLists(most_recent->next, lists[i]);
            }
            return most_recent->next;
        }
};