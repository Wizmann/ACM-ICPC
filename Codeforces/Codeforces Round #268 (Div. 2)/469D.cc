//Result: 2014-10-06 17:40:26	intgraph0	D - Two Sets	GNU C++0x	Accepted	202 ms	7408 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int n, a, b;
int father[SIZE];
int nums[SIZE];
set<int> st;
map<int, int> mp;

void init(int n) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

int find_father(int x) {
    if (father[x] == x) {
        return x;
    } else {
        return father[x] = find_father(father[x]);
    }
}

// a -> b
void connect(int a, int b) {
    father[find_father(a)] = find_father(b);
}

int main()
{
    int x;
    input(n >> a >> b);
    init(n + 10);
    int A = n, B = n + 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        nums[i] = x;
        st.insert(x);
        mp[x] = i;
    }

    for (int i = 0; i < n; i++) {
        int aa = a - nums[i];
        int bb = b - nums[i];

        if (st.find(aa) != st.end()) {
            connect(i, mp[aa]);
        } else {
            connect(i, B);
        }

        if (st.find(bb) != st.end()) {
            connect(i, mp[bb]);
        } else {
            connect(i, A);
        }
    }

    if (find_father(A) == find_father(B)) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            int f = find_father(i);
            printf("%d ", f == find_father(A)? 0: 1);
        }
        puts("");
    }
    return 0;
}

