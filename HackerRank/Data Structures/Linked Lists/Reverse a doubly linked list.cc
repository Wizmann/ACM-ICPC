/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    if (!head) {
        return NULL;
    }
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    while (head) {
        Node* next = head->next;
        swap(head->next, head->prev);
        head = next;
    }
    return tail;
}

