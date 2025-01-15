class Solution(object):
    def addTwoNumbers(self, l1, l2):
        ptr1 = l1
        ptr2 = l2
        carry = 0 
        finalAns = []
        ans = ListNode()
        currNode = ans 

        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            val = v1 + v2 + carry 
            
            carry = val // 10 
            val = val % 10 
            currNode.next = ListNode(val)
            
            currNode = currNode.next 
            l1 = l1.next if l1 else None 
            l2 = l2.next if l2 else None 
        return ans.next 
