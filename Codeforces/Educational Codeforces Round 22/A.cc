#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n, m;

int main() {
    input(n);
    int a, b;
    int s = 0;
    for (int i = 0; i < n; i++) {
        input(a);
        s += a;
    }

    input(m);
    bool flag = false;
    for (int i = 0; i < m && !flag; i++) {
        input(a >> b);
        if (a <= s && s <= b) {
            flag = true;
        } else if (s <= a) {
            s = a;
            flag = true;
        }
    }

    if (flag) {
        print(s);
    } else {
        print(-1);
    }

    return 0;
}
