/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode **pre = &head;
        ListNode *nowNode = head;
        
        if (k == 1) {
            return head;
        }
        
        while (nowNode) {
            ListNode *headNode = nowNode;
            ListNode *tailNode = nowNode;
            int step = 0;
            for (int i = 0; i < k - 1; i++) {
                if (tailNode -> next) {
                    tailNode = tailNode -> next;
                    step++;
                } else {
                    break;
                }
            }
            
            if (step != k - 1) {
                *pre = headNode;
                break;
            }
            
            ListNode *nextBlock = tailNode -> next;
            *pre = _reverseK(headNode, tailNode);
            headNode -> next = nextBlock;
            pre = &(headNode -> next);
            nowNode = nextBlock;
        }
        return head;
    }
    
    ListNode* _reverseK(ListNode* nowNode, ListNode* nextNode)
    {
        ListNode *nextBlock = nextNode -> next;
        nextNode -> next = NULL;
        return _reverse(nextBlock, nowNode);
    }
    
    ListNode* _reverse(ListNode* preNode, ListNode* nowNode)
    {
        ListNode *_next = nowNode -> next;
        nowNode -> next = preNode;
        if (_next == NULL) {
            return nowNode;
        } else {
            return _reverse(nowNode, _next);
        }
    }
};
