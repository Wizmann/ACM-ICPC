// Result: 6134469   Mar 25, 2014 7:27:15 AM    Wizmann  D - Toy Sum     GNU C++0x  Accepted    218 ms  6664 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define input(_) cin >> _
#define print(_) cout << _ << endl

const int SIZE = 1000000;

char nums[SIZE + 100];
vector<int> xs, ys;

inline int symmetric(int u)
{
    return SIZE + 1 - u;
}

int main()
{
    int n, x;
    input(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        nums[x] = 1;
        xs.push_back(x);
    }

    int zs = 0;
    for (auto iter = xs.begin(); iter != xs.end(); ++iter) {
        int u = *iter;
        int v = symmetric(u);

        if (nums[u] && nums[v]) {
            zs++;
        } else {
            ys.push_back(v);
        }
    }

    zs >>= 1;
    for (int i = 1; i <= SIZE && zs; i++) {
        int u = i;
        int v = symmetric(u);

        if (!nums[u] && !nums[v]) {
            ys.push_back(u);
            ys.push_back(v);
            zs--;
        }
    }
    
    printf("%d\n", (int)ys.size());
    for (auto iter = ys.begin(); iter != ys.end(); ++iter) {
        printf("%d ", *iter);
    }
    puts("");
    return 0;
}

