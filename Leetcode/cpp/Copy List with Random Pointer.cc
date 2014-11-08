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
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* ptr = head;
        while (head) {
            RandomListNode* mirror = find_mirror_or_add(head, mp);
            mirror -> label = head -> label;
            head = head -> next;
        }
        
        head = ptr;
        RandomListNode* res = mp[head];
        while (head) {
            res -> next = mp[head -> next];
            res -> random = mp[head -> random];
            res = res -> next;
            head = head -> next;
        }
        head = ptr;
        return mp[head];
    }
    
    RandomListNode* find_mirror_or_add(RandomListNode* node_ptr, map<RandomListNode*, RandomListNode*>& mp) {
        auto iter = mp.find(node_ptr);
        if (iter == mp.end()) {
            mp[node_ptr] = new RandomListNode(-1);
        }
        return mp[node_ptr];
    }
};
