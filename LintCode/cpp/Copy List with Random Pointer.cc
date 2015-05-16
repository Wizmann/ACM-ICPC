/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* cur = head;
        while (cur) {
            RandomListNode* new_cur = new RandomListNode(cur->label);
            new_cur->next = cur->next;
            new_cur->random = cur->random;
            cur->next = new_cur;
            
            cur = new_cur->next;
        }
        
        cur = head;
        RandomListNode* new_head = cur->next;
        while (cur) {
            RandomListNode* new_cur = cur->next;
            if (new_cur->random) {
                new_cur->random = new_cur->random->next;
            }
            cur = new_cur->next;
        }
        
        cur = head;
        while (cur) {
            RandomListNode* new_cur = cur->next;
            cur->next = new_cur->next;
            if (new_cur->next) {
                new_cur->next = new_cur->next->next;
            }
            cur = cur->next;
        }
        
        return new_head;
    }
};
