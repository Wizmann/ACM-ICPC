class LinkedListNode(object):
    def __init__(self, val):
        self.val = val
        self.next = None

class MyLinkedList(object):
    def __init__(self):
        self.dummy_head = LinkedListNode(-1)
        
    def get(self, index):
        head = self.dummy_head.next
        for i in xrange(index):
            if not head:
                break
            head = head.next
        return -1 if not head else head.val
        
    def addAtHead(self, val):
        head = LinkedListNode(val)
        self.dummy_head.next, head.next = head, self.dummy_head.next

    def addAtTail(self, val):
        tail = self.dummy_head
        while tail.next:
            tail = tail.next
        tail.next = LinkedListNode(val)
        tail = tail.next

    def addAtIndex(self, index, val):
        if index == 0:
            self.addAtHead(val)
            return
        head = self.dummy_head.next
        for i in xrange(index - 1):
            if not head:
                break
            head = head.next
        if head:
            cur = LinkedListNode(val)
            head.next, cur.next = cur, head.next

    def deleteAtIndex(self, index):
        if index == 0:
            self.dummy_head.next = self.dummy_head.next.next
            return
        head = self.dummy_head.next
        for i in xrange(index - 1):
            if not head:
                break
            head = head.next
        if head:
            head.next = None if not head.next else head.next.next
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
