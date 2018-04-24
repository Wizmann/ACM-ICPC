#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 62;

vector<llint> offset;

int level(llint u) {
    int cnt = 0;
    while (u) {
        cnt++;
        u /= 2;
    }
    return cnt;
}

void traverse(llint cur) {
    int l = level(cur);
    llint base = 1LL << (l - 1);
    llint diff = cur - base + offset[l];
    cur = (diff % base + base) % base + base;    
    
    for (int i = l; i > 0; i--) {
        base = 1LL << (i - 1);
        diff = cur - base - offset[i];
        llint u = (diff % base + base) % base + base;
        printf("%I64d ", u);

        cur = cur / 2;
    }
    puts("");
}

int main() {
    int Q;
    input(Q);

    int cmd;
    llint a, b;

    offset.resize(SIZE);

    while (Q--) {
        input(cmd);
        if (cmd == 1) {
            scanf("%I64d%I64d", &a, &b);
            int l = level(a);
            llint base = 1LL << (l - 1);

            b = (b % base + base) % base;
            offset[l] = (base + offset[l] + b % base) % base;
        } else if (cmd == 2) {
            scanf("%I64d%I64d", &a, &b);
            int l = level(a);

            for (int i = l; i < SIZE; i++) {
                llint base = 1LL << (i - 1);
                b = (b % base + base) % base;
                offset[i] = (base + offset[i] + b % base) % base;
                
                b = (b * 2);
            }
        } else {
            scanf("%I64d", &a);
            traverse(a);
        }
    }
   
    return 0;
}
