#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode *res = NULL;
        ListNode *p = NULL;
        int g = 0;
        while(l1 || l2 || g)
        {
            int a = 0, b = 0;
            if(l1)
            {
                a = l1->val;
                l1 = l1 -> next;
            }
            if(l2)
            {
                b = l2->val;
                l2 = l2 -> next;
            }
            ListNode *tmp = new ListNode((a+b+g)%10);
            g = (a+b+g)/10;
            if(!res)
            {
                res = tmp;
                p = res;
            }
            else
            {
                p -> next = tmp;
                p = p -> next;
            }
        }
        return res;
    }
};