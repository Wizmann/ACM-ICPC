# Definition for singly-linked list with a random pointer.
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if not head:
            return None
            
        cur = head
        while cur:
            next = cur.next
            cur.next = RandomListNode(cur.label)
            cur.next.next = next
            cur = next
            
        cur = head
        while cur:
            random_node = cur.random
            cur = cur.next
            if random_node:
                cur.random = random_node.next
            cur = cur.next
        
        cur = head
        new_head = cur.next
        new_cur = cur.next
        while cur:
            cur.next = cur.next.next
            new_cur.next = new_cur.next.next if new_cur.next else None
            
            cur = cur.next
            new_cur = new_cur.next
        return new_head
