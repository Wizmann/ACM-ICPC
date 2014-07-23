// Result: Wizmann 1518 Accepted 1520KB 1667B 170MS 23:24:17
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << endl

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int n;
ListNode *head, *tail;

void push_back(int a)
{
    if (!head) {
        head = tail = new ListNode(a);
    } else {
        tail -> next = new ListNode(a);
        tail = tail -> next;
    }
}

void do_reverse()
{
    ListNode *a = NULL, *b = head;
    while (b) {
        ListNode *c = b -> next;
        b -> next = a;
        a = b;
        b = c;
    }
    head = a;
}

void do_traverse()
{
    bool first = true;
    ListNode *a = head;
    while (a) {
        if (first) {
            first = false;
        } else {
            printf(" ");
        }
        printf("%d", a -> val);
        a = a -> next;
    }
    puts("");
}

void do_free(ListNode *a)
{
    if (a) {
        do_free(a -> next);
        delete a;
    }
}

int main()
{
    int a;
    while (input(n)) {
        if (!n) {
            print("NULL");
            continue;
        }
        head = tail = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            push_back(a);
        }
        //do_traverse();
        do_reverse();
        do_traverse();
        do_free(head);
    }
    return 0;
}


