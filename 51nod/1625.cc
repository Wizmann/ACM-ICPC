#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

vector<vector<llint> > matrix;
int n, m, k;
llint value_x;

inline int lowbit(int x) {
    return x & (-x);
}

int count_bit(int x) {
    int res = 0;
    while (x) {
        res++;
        x -= lowbit(x);
    }
    return res;
}

inline bool test_bit(int a, int b) {
    return a & (1 << b);
}

llint solve(int x) {
    priority_queue<llint, vector<llint>, greater<llint> > pq;
    llint thres = value_x * n;

    llint res = 0;
    for (int i = 0; i < m; i++) {
        llint sum = 0;
        for (int j = 0; j < n; j++) {
            if (test_bit(x, j)) {
                sum += value_x;
            } else {
                sum += matrix[j][i];
            }
        }
        res += sum;
        if (sum < thres) {
            pq.push(sum);
        }
    }

    int step = k - count_bit(x);
    for (int i = 0; i < step && !pq.empty(); i++) {
        llint diff = thres - pq.top();
        pq.pop();
        res += diff;
    }
    return res;
}

int main() {
    while (input(n >> m >> value_x >> k)) {
        matrix = vector<vector<llint> >(n, vector<llint>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lld", &matrix[i][j]);
            }
        }

        llint ans = numeric_limits<llint>::min();
        for (int i = 0; i < (1 << n); i++) {
            if (count_bit(i) > k) {
                continue;
            }
            ans = max(ans, solve(i));
        }
        print(ans);
    }
    return 0;
}
