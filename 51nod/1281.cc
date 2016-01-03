#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<int> points;
vector<int> flags;
vector<int> dis;

bool check(int m) {
    int cnt = 0;
    int pre = 0;
    for (auto d: dis) {
        pre += d;
        if (pre >= m) {
            cnt++;
            pre = 0;
        }
    }
    return cnt + 1 >= m;
}

int main() {
    input(n);
    points.resize(n);
    flags.reserve(n);
    dis.reserve(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i]);
    }
    
    for (int i = 1; i < n - 1; i++) {
        if (points[i - 1] < points[i] && points[i] > points[i + 1]) {
            flags.push_back(i);
        }
    }
    
    int m = flags.size();
    
    if (m == 0) {
        print(0);
        return 0;
    }
    
    for (int i = 1; i < m; i++) {
        dis.push_back(flags[i] - flags[i - 1]);
    }
    
    int l = 0;
    int r = n;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    print(r);
    return 0;
}
