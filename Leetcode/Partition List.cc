class Solution {
public:
    ListNode *left, *right;
    ListNode *lefttail, *righttail;

    ListNode *partition(ListNode *head, int x) 
    {
        left=right=lefttail=righttail=NULL;
        ListNode *ptr = head;
        while(ptr)
        {
            if(ptr->val < x)
            {
                Insert(left, lefttail, ptr->val);
            }
            else
            {
                Insert(right, righttail, ptr->val);
            }
            ptr = ptr->next;
        }
        if(left)
        {
            lefttail->next = right;
            return left;
        }
        else if(right)
        {
            return right;
        }
        else return NULL;
    }
    void Insert(ListNode*& head, ListNode*& tail, int val)
    {
        if(!head)
        {
            head = new ListNode(val);
            tail = head;
        }
        else
        {
            ListNode *tmp = new ListNode(val);
            tail->next = tmp;
            tail = tail->next;
        }
    }
};
