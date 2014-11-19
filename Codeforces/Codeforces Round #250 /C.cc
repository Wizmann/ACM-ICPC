#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024;

int n, m;
int value[SIZE];

int main()
{
    freopen("c.txt", "r", stdin);
    int a, b;
    input(n >> m);
    for (int i = 1; i <= n; i++) {
        input(value[i]);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        input(a >> b);
        ans += min(value[a], value[b]);
    }
    print (ans);
    return 0;
}

