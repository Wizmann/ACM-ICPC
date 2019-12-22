#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
const int INF = 0x3f3f3f3f;
const int SIZE = 212345;
 
char buffer[SIZE];
 
bool dfs(const vector<int>& ns, int cur, int k, bool gt, vector<int>& tmp) {
    if (cur == ns.size()) {
        return true;
    }
 
    int pre = cur - k < 0? -1: tmp[cur - k];
 
    for (int i = 0; i < 10; i++) {
        if (pre != -1 && pre != i) {
            continue;
        }
 
        if (i < ns[cur]) {
            if (!gt) {
                continue;
            }
 
            tmp[cur] = i;
            bool flag = dfs(ns, cur + 1, k, gt, tmp);
            if (flag) {
                return true;
            }
            tmp[cur] = -1;
        } else if (i == ns[cur]) {
            tmp[cur] = i;
            bool flag = dfs(ns, cur + 1, k, gt, tmp);
            if (flag) {
                return true;
            }
            tmp[cur] = -1;
        } else {
            tmp[cur] = i;
            bool flag = dfs(ns, cur + 1, k, true, tmp);
            if (flag) {
                return true;
            }
            tmp[cur] = -1;
        }
    }
 
    return false;
}
 
int main() {
    int n, k;
    input(n >> k);
 
    scanf("%s", buffer);
 
    vector<int> ns(n + 1, 0);
 
    for (int i = 1; i <= n; i++) {
        ns[i] = buffer[i - 1] - '0';
    }
 
 
    vector<int> tmp(n + 1, -1);
    bool flag = dfs(ns, 1, k, false, tmp);
    assert(flag == true);
 
    print(n);
    for (int i = 1; i <= n; i++) {
        printf("%d", tmp[i]);
    }
    puts("");
    
    return 0;
}
