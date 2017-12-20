# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        length, ptr = 0, root
        while ptr:
            length += 1
            ptr = ptr.next
        
        res = []
        ptr = root
        for i in xrange(k):
            section = length / (k - i)
            remains = length % (k - i)
            
            head = ptr
            
            if head == None:
                res.append([])
                continue
            
            if remains:
                section += 1
            for j in xrange(section - 1):
                ptr = ptr.next
            if ptr:
                next = ptr.next
                ptr.next = None
            res.append(head)
            ptr = next
            
            length -= section
        return res
            
        
