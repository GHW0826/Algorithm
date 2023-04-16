# python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        quo = int((l1.val + l2.val) // 10)
        answer = ListNode((l1.val + l2.val) % 10)
        ptr = answer
        l1 = l1.next
        l2 = l2.next
        while (l1 is not None or l2 is not None):
            val1 = int(l1.val if l1 is not None else 0)
            val2 = int(l2.val if l2 is not None else 0)
            val = int(val1 + val2 + quo)
            quo = val // 10

            ptr.next = ListNode(val % 10)
            ptr = ptr.next
            l1 = l1.next if l1 is not None else l1
            l2 = l2.next if l2 is not None else l2
        if (quo > 0):
            ptr.next = ListNode(quo)
        return answer
  
# python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        quo = int((l1.val + l2.val) // 10)
        answer = ListNode((l1.val + l2.val) % 10)
        ptr = answer
        l1 = l1.next
        l2 = l2.next
        while (l1 or l2):
            val1 = int(l1.val if l1 else 0)
            val2 = int(l2.val if l2 else 0)
            val = int(val1 + val2 + quo)
            quo = val // 10

            ptr.next = ListNode(val % 10)
            ptr = ptr.next
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
        if (quo > 0):
            ptr.next = ListNode(quo)
        return answer
