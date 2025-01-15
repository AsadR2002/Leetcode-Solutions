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
        int carry = 0; //Carry is used to store the carry value if sum > 9
        ListNode* ans = new ListNode(); //Dummy node to start list 
        ListNode* currNode = ans; //Real node moved through as list updated

        while(l1 || l2 || carry){ //while either node or carry is left 
            int v1 = l1 != nullptr ? l1->val : 0; 
            int v2 = l2 != nullptr ? l2->val : 0; 
            int val = v1 + v2 + carry; //calculate value

            carry = val / 10; // will return 0 if val < 10, 1 if val > 10
            val = val % 10; // return remainder of val that is not in carry

            ListNode* newNode = new ListNode(val); // create node to insert

            currNode->next = newNode;  //insert that node 
            currNode = currNode->next; //insert the next node 
        
            l1 = l1 ? l1->next : NULL; //shift pointers over 
            l2 = l2 ? l2->next : NULL;
        }

        return ans->next; //return answer which starts after dummy node 
         
    }
};