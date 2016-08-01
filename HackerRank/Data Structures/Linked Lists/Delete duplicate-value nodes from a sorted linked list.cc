/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

const int INF = 0x3f3f3f3f;

Node* RemoveDuplicates(Node *head)
{
    Node dummy_head;
    
    dummy_head.next = head;
    dummy_head.data = INF;
    
    head = &dummy_head;
    
    Node* ptr = head;
    while (ptr) {
        if (ptr->next && ptr->data == ptr->next->data) {
            ptr->next = ptr->next->next;
        } else {
            ptr = ptr->next;
        }
    }
    return dummy_head.next;
}

