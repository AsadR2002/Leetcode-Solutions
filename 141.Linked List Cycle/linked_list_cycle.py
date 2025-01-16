# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        l, r = head, head
        while r and r.next:
            l = l.next
            r = (r.next).next 
            if l == r:
                return True

        return False
        
        """
        :type head: ListNode
        :rtype: bool
        """
        