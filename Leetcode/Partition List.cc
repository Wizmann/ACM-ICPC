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
    ListNode *partition(ListNode *head, int x) {
        pair<ListNode*, ListNode*> left, right;
        left = right = make_pair<ListNode*, ListNode*>((ListNode*)NULL, (ListNode*)NULL);
        while (head != NULL) {
            auto& now = head -> val < x ? left: right;
            
            if (now.first == NULL) {
                now.first = now.second = head;
            } else {
                (now.second) -> next = head;
                now.second = head;
            }
            
            head = head -> next;
            (now.second) -> next = NULL;
        }
        
        if (left.first) {
            (left.second) -> next = right.first;
        } else {
            left = right;
        }
        right.second = NULL;
        return left.first;
    }
};
