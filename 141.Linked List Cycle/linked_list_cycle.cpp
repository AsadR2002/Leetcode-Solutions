/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) { // solution uses Floyd's cycle-finding algorithm
        ListNode *slow = head; 
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){ //If no cycle, fast pointer will reach the end of the list
            slow = slow->next;
            fast = (fast->next)->next; //fast pointer traverses twice as fast as slow pointer
            if(slow == fast){ //if there is a cycle, the two pointers will meet at some point
                return true;
            }
        }
        return false;
    }
};