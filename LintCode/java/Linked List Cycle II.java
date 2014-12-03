/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 

/*
Test Case: 
1) NULL
2) 1 -> NULL
3) 1 -> 2 -> NULL
4) 1 -> 2 -> 3 -> NULL
5) 1 -> 2 -> 3 -> 4 -> NULL
6) 1 -> 2
   ^----|
7) 1 -> 2 -> 3
   ^---------|
8) 1 -> 2 -> 3
        ^----|

*/

public class Solution {
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    public ListNode detectCycle(ListNode head) {  
        if (head == null) {
            return null;
        }
        ListNode a, b;
        a = b = head;
        
        while (a != null && b != null) {
            a = a.next;
            b = b.next;
            if (b != null) {
                b = b.next;
            }
            if (a == b) {
                break;
            }
        }
        
        if (a == null || b == null) {
            return null;
        }
        
        a = head;
        
        while (a != b) {
            a = a.next;
            b = b.next;
        }
        return a;
    }
}

