class LinkedList {
public:
    LinkedList(): head(nullptr), tail(nullptr) {}

    bool empty() {
        return head == nullptr;
    }
    
    void append(ListNode* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        tail->next = nullptr;
    }
    
    void extend(LinkedList* llist) {
        if (llist->empty()) {
            return;
        }
        if (this->empty()) {
            *this = *llist;
            return;
        }
        tail->next = llist->head;
        tail = llist->tail;
    }
    
    ListNode* get_head() {
        return head;
    }
    
    ListNode* get_tail() {
        return tail;
    }
    
    void show() {
        auto iter = head;
        while (iter) {
            printf("%d ", iter->val);
            if (iter == tail) {
                break;
            }
            iter = iter->next;
        }
        puts("");
    }
private:
    ListNode* head;
    ListNode* tail;
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        LinkedList a, b;
        for (int i = 0; head; i++) {
            ListNode* next = head->next;
            if (i % 2 == 0) {
                a.append(head);
            } else {
                b.append(head);
            }
            head = next;
        }
        a.extend(&b);
        return a.get_head();
    }
};
