def Insert(head, data):
    dummy_head = Node(-1)
    dummy_head.next = head
    head = dummy_head
    while head.next:
        head = head.next
    head.next = Node(data)
    return dummy_head.next
