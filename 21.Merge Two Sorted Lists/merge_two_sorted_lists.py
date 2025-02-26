# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        head = ListNode()
        curr = head 
        l1, l2 = list1, list2 
        while l1 or l2:
            if not l1:
                curr.next = l2
                return head.next
            if not l2:
                curr.next =  l1
                return head.next
            else: 
                if l1.val < l2.val:
                    curr.next = l1
                    l1 = l1.next
                else:
                    curr.next = l2
                    l2 = l2.next 
                curr = curr.next
        return head.next

        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        