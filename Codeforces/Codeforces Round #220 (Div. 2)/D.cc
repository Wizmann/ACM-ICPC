//Result: 5486606    Dec 21, 2013 3:31:01 PM    Wizmann  D - Inna and Sequence   GNU C++    Accepted     951 ms  23500 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1001000;

int n, m;

int hit[SIZE];
int hitcnt[SIZE];
int hitsum[SIZE];
int goback[SIZE];
int number[SIZE];
int pos[SIZE];

int main()
{
    freopen("input.txt", "r", stdin);
    int x;
    input(n >> m);
    
    memset(hit, 0, sizeof(hit));
    memset(hitsum, 0, sizeof(hit));

    for (int i = 0; i < m; i++) {
        input(x);
        hit[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        hitsum[i] += hit[i] + (i - 1 >= 0? hitsum[i - 1] : 0);
    }

    //goback[i]数组代表在第几次hit之后, 第i个棋子会出局
    memset(goback, 0, sizeof(goback));
    for (int i = 1; i <= n; i++) {
        if (hit[i]) {
            goback[i] = 1;
        } else {
            if (hitsum[i] == 0) {
                goback[i] = -1;
            } else {
                goback[i] = goback[i - hitsum[i]] + 1;
            }
        }
    }

    int len = 0;
    memset(pos, 0, sizeof(pos));
    memset(hitcnt, 0, sizeof(hitcnt));
    for (int i = 1; i <= n; i++) {
        input(number[i]);
        if (number[i] == -1) {
            len -= hitsum[len];
        } else {
            len++;
            pos[i] = len;
        }

        hitcnt[i] = hitcnt[i - 1] + (number[i] == -1);
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (number[i] == -1) {
            continue;
        }

        if (goback[pos[i]] == -1 ||
            goback[pos[i]] > hitcnt[n] - hitcnt[i]) {
            printf("%d", number[i]);
            flag = true;
        } 
    }

    if (flag) {
        puts("");
    } else {
        puts("Poor stack!");
    }

    return 0;
}
