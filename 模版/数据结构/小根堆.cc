#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 100100;

int pq[SIZE];
int idx;

inline int left(int x) {return 2 * x + 1;}
inline int right(int x) { return 2 * x + 2;}
inline int parent(int x) {return (x - 1) >> 1;}

void init()
{
    memset(pq, 0, sizeof(pq));
    idx = 0;
}

void _up()
{
    int now = idx - 1;
    while (now) {
        if (pq[parent(now)] > pq[now]) {
            swap(pq[parent(now)], pq[now]);
            now = parent(now);
        } else {
            break;
        }
    }
}
    
void _down(int now)
{
    if (left(now) < idx && pq[now] > pq[left(now)]) {
        swap(pq[now], pq[left(now)]);
        _down(left(now));
    }
    
    if (right(now) < idx && pq[now] > pq[right(now)]) {
        swap(pq[now], pq[right(now)]);
        _down(right(now));
    }
}


void push(int x)
{
    pq[idx++] = x;
    _up();
}

int pop()
{
    int res = pq[0];
    pq[0] = pq[--idx];
    _down(0);
    return res;
}

int main()
{
    int T, a, b, n;
    input(T);
    while (T--) {
        init();
        input(n);
        while (n--) {
            input(a);
            if (a == 1) {
                input(b);
                push(b);
            } else {
                b = pop();
                print(b);
            }
        }
    }
    return 0;
}
