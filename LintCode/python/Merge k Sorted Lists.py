"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
import heapq

INF = 10 ** 10

class Solution:
    """
    @param lists: a list of ListNode
    @return: The head of one sorted list.
    """
    def mergeKLists(self, lists):
        pq = []
        dummyHead = ListNode(-1)
        tailNode = dummyHead
        for l in lists:
            heapq.heappush(pq, (-INF if l is None else l.val, l))
            
        while pq:
            (v, l) = heapq.heappop(pq)
            if l is None:
                continue
            tailNode.next = ListNode(v)
            tailNode = tailNode.next
            
            l = l.next
            heapq.heappush(pq, (-INF if l is None else l.val, l))
        
        return dummyHead.next

