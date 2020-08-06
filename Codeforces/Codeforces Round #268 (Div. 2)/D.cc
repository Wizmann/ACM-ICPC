#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class DisjointSet
{
public:
    DisjointSet(int n_) : n(n_), father(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

    void make_union(int a, int b) {
        father[find_father(b)] = find_father(a);
    }
private:
    int n;
    vector<int> father;
};

int main() {
    int n, a, b;
    input(n >> a >> b);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    DisjointSet ds(n + 2);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[ns[i]] = i;
    }

    const int A = n;
    const int B = n + 1;

    for (int i = 0; i < n; i++) {
        int x = ns[i];
        int y = a - ns[i];
        int z = b - ns[i];
        if (mp.count(y) == 0 && mp.count(z) == 0) {
            ds.make_union(A, B);
            break;
        } else if (mp.count(y) != 0 && mp.count(z) != 0) {
            ds.make_union(i, mp[y]);
            ds.make_union(i, mp[z]);
        } else if (mp.count(y) != 0) {
            ds.make_union(A, i);
            ds.make_union(A, mp[y]);
        } else if (mp.count(z) != 0) {
            ds.make_union(B, i);
            ds.make_union(B, mp[z]);
        } else {
            assert(false);
        }
    }

    if (ds.find_father(A) == ds.find_father(B)) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            if (ds.find_father(i) == ds.find_father(A)) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        puts("");
    }

    return 0;
}
