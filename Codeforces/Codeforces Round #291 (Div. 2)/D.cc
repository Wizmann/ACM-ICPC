#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int TYPE = 5;

namespace RMQ {
struct RMQArray {
    void init(const vector<int>& vec) {
        _rmq_maxi.clear();
        _rmq_mini.clear();

        int n = vec.size();
        int m = int(log2(n) + 1);

        _rmq_maxi.resize(m + 1);
        _rmq_mini.resize(m + 1);

        for (auto& arr: _rmq_maxi) {
            arr.resize(n);
        }
        for (auto& arr: _rmq_mini) {
            arr.resize(n);
        }

        _rmq_maxi[0] = vec;
        _rmq_mini[0] = vec;

        init_rmq(n, m);
    }

    void init_rmq(int n, int m) {
        for (int j = 1; j <= m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                _rmq_maxi[j][i] = _rmq_maxi[j - 1][i];
                _rmq_mini[j][i] = _rmq_mini[j - 1][i];

                if (i + (1 << (j - 1)) < n) {
                    _rmq_maxi[j][i] = max(
                            _rmq_maxi[j][i],
                            _rmq_maxi[j - 1][i + (1 << (j - 1))]);
                    _rmq_mini[j][i] = min(
                            _rmq_mini[j][i],
                            _rmq_mini[j - 1][i + (1 << (j - 1))]);
                }
            }
        }
    }

    int range_max(int l, int r) {
        int m = log2(r - l + 1);
        return max(_rmq_maxi[m][l], _rmq_maxi[m][r - (1 << m) + 1]);
    }

    int range_min(int l, int r) {
        int m = log2(r - l + 1);
        return min(_rmq_mini[m][l], _rmq_mini[m][r - (1 << m) + 1]);
    }

    vector<vector<int> > _rmq_maxi;
    vector<vector<int> > _rmq_mini;
};
} // namespace RMQ

int n, m, k;
vector<int> detail_nums[5];
RMQ::RMQArray rmq_arrays[TYPE];

int main() {
    freopen("input.txt", "r", stdin);
    int a;
    input(n >> m >> k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input(a);
            detail_nums[j].push_back(a);
        }
    }
    for (int i = 0; i < m; i++) {
        rmq_arrays[i].init(detail_nums[i]);
    }

    int p = 0;
    int q = 0;
    int ans = 0;
    vector<int> ans_vec;
    ans_vec.resize(m);

    while (q < n) {
        while (p <= q) {
            int sum = 0;
            vector<int> res;
            for (int i = 0; i < m; i++) {
                int t = rmq_arrays[i].range_max(p, q);
                // printf("[%d] (%d, %d) : %d\n", i, p, q, t);
                res.push_back(t);
                sum += t;
            }
            if (sum > k) {
                p++;
            } else {
                if (q - p + 1 > ans) {
                    ans = q - p + 1;
                    ans_vec = res;
                }                    
                break;
            }
        }
        q++;
    }
    // print(ans);
    for (auto i: ans_vec) {
        printf("%d ", i);
    }
    puts("");

    return 0;
};
