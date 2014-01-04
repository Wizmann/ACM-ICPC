#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 200100;

int n, m;
llint cap[SIZE];
llint vessel[SIZE];

int father[SIZE];

int find_father(int x)
{
    if (father[x] == x) return x;
    else return father[x] = find_father(father[x]);
}

void pour(int pos, llint value) {
    vessel[pos] += value;
    if (vessel[pos] > cap[pos]) {
        if (pos == n - 1) {
            vessel[pos] = cap[pos];
            return;
        } else {
            llint overflow = vessel[pos] - cap[pos];
            father[pos] = find_father(pos + 1);
            vessel[pos] = cap[pos];
            pour(father[pos], overflow);
        }
    }
}

llint query(int pos)
{
    return vessel[pos];
}

int main()
{
    freopen("input.txt", "r", stdin);
    llint a, b, c;
    input(n);

    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }

    memset(cap, 0, sizeof(cap));
    memset(vessel, 0, sizeof(vessel));

    for (int i = 0; i < n; i++) {
        input(cap[i]);
    }

    input(m);
    while (m--) {
        input(a);
        if (a == 1) {
            input(b >> c);
            pour(--b, c);
        } else {
            input(b);
            print(query(--b));
        }
    }
    
    return 0;
}
