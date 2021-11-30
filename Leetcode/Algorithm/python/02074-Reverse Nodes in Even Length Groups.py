# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseEvenLengthGroups(self, head):
        return self.reverse(head, 0)
    
    def reverse(self, cur, group):
        if not cur:
            return None
        
        first = cur
        last = cur
        length = 0
        
        for i in xrange(group):
            if last and last.next:
                last = last.next
                length += 1
        
        nxt = last.next
        
        if length % 2 == 1:
            self.do_reverse(first, last)
            first.next = self.reverse(nxt, group + 1)
            return last
        else:
            last.next = self.reverse(nxt, group + 1)
            return first
    
    def do_reverse(self, first, last):
        head = ListNode()
        tail = last.next
        
        while first and first != tail:
            nxt = first.next
            first.next = head.next
            head.next = first
            first = nxt
        return head.next
        
        
