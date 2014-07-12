#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) do { cout << x << endl; } while(0)
#define input(x) cin >> x

const int SIZE = 56;

typedef long long llint;

int n, m;
int father[SIZE];

int findfather(int x)
{
    if (father[x] == x) {
        return x;
    } else {
        return father[x] = findfather(father[x]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n >> m);
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
    while (m--) {
        input(a >> b);
        father[findfather(a)] = findfather(b);
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(findfather(i));
    }
    print((1LL << (n - st.size())));
    return 0;
}
