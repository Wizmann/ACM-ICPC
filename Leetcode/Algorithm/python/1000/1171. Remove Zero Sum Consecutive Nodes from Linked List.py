# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeZeroSumSublists(self, head):
        l = []
        s = set([0])
        pre = 0
        while head:
            pre += head.val
            l.append(head)
            
            #print pre, s
            while pre in s:
                s.remove(pre)
                pre = pre - l.pop().val
            else:
                s.add(pre)
            head = head.next

        dummyHead = ListNode(-1)
        cur = dummyHead
        for item in l:
            cur.next = item
            cur = cur.next
        if l:
            l[-1].next = None
        return dummyHead.next

def makeList(l):
    dummyHead = ListNode(-1)
    cur = dummyHead
    for item in l:
        cur.next = ListNode(item)
        cur = cur.next
    return dummyHead.next

def getList(head):
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res
