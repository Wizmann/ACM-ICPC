/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        }
        ListNode l3 = new ListNode(-1);
        ListNode p3 = l3;
        
        int g = 0;
        while (l1 != null || l2 != null || g != 0) {
            int a = (l1 == null)? 0: l1.val;
            int b = (l2 == null)? 0: l2.val;
            
            p3.next = new ListNode((a + b + g) % 10);
            g = (a + b + g) / 10;
            p3 = p3.next;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        return l3.next;
    }
}
