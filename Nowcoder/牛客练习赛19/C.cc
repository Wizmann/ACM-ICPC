#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
const int MOD = 420047;
 
bool check(int n, int m, int a, int b) {
    int y1 = a / n;
    int x1 = a % n;
 
    int y2 = b / n;
    int x2 = b % n;
 
    if (y1 == y2 && abs(x1 - x2) <= 1) {
        return false;
    }
 
    if (x1 == x2 && abs(y1 - y2) <= 1) {
        return false;
    }
 
    return true;
}
 
bool check(int n, int m, const vector<int>& points) {
    int cnt = points.size();
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (!check(n, m, points[i], points[j])) {
                return false;
            }
        }
    }
    return true;
}
 
int dfs(int n, int m, int pre, int k, vector<int>& points) {
    if (points.size() == k) {
        return check(n, m, points);
    }
 
    int res = 0;
    for (int i = pre + 1; i < n * m; i++) {
        if (pre != -1 && !check(n, m, pre, i)) {
            continue;
        }
        points.push_back(i);
        res += dfs(n, m, i, k, points);
        points.pop_back();
    }
    return res % MOD;
}
 
int main() {
    int T;
    input(T);
    while (T--) {
        int n, m, k;
        input(n >> m >> k);
 
        int tot = n * m;
        vector<int> points;
        int cnt = dfs(n, m, -1, k, points);
        print(cnt % MOD);
    }
    return 0;
}