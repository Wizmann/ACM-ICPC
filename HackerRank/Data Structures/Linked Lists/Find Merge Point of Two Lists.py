def FindMergeNode(headA, headB):
    s = set()
    while headA:
        s.add(headA)
        headA = headA.next
    while headB:
        if headB in s:
            return headB.data
        headB = headB.next
    return None
  
