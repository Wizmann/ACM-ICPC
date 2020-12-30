/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var p1 = l1
        var p2 = l2
        var g = 0
        var dummyHead = ListNode(-1)
        var p = dummyHead
        
        while (p1 != null || p2 != null || g != 0) {
            var u = g + (p1?.`val` ?: 0) + (p2?.`val` ?: 0)
            p.next = ListNode(u % 10)
            g = u / 10
            p1 = p1?.next
            p2 = p2?.next
            p = p.next
        }
        return dummyHead.next
    }
}
