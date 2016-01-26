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

const int SIZE = 123456;

struct Query {
    int a, b;
    int res;
};

int n, q;
vector<Query> queries;
vector<int> father;
map<int, int> mp;

void init() {
    father.resize(SIZE * 2);
    for (int i = 0; i < SIZE * 2; i++) {
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
    father[find_father(a)] = find_father(b);
}

int opp(int x) {
    return x + SIZE;
}

int main() {
    int a, b, c;
    char s[30];
    input(n >> q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%s", &a, &b, s);
        c = (*s == 'o'? 1: 0);
        queries.push_back({a, b, c});
        mp.insert({a - 1, -1});
        mp.insert({b, -1});
    }
    
    int idx = 1;
    for (auto& p: mp) {
        p.second = idx++;
    }

    init();
    
    bool flag = false;
    for (int i = 0; i < q; i++) {
        a = queries[i].a;
        b = queries[i].b;
        c = queries[i].res;

        a = a - 1;
        
        a = mp[a];
        b = mp[b];
        
        if (c == 0) {
            if (find_father(a) == find_father(opp(b))) {
                print(i + 1);
                flag = true;
                break;
            }
            make_union(a, b);
            make_union(opp(a), opp(b));
        } else {
            if (find_father(a) == find_father(b)) {
                print(i + 1);
                flag = true;
                break;
            }
            make_union(a, opp(b));
            make_union(opp(a), b);
        }
    }
    if (!flag) {
        puts("-1");
    }
    return 0;
}
