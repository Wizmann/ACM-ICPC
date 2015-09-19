#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

class BinaryIndexedTree {
    public:
        void init(int n) {
            _tree.resize(n);
            fill(_tree.begin(), _tree.end(), 0);
        }

        void add(int pos, int value) {
            while (pos < _tree.size()) {
                _tree[pos] += value;
                pos += lowbit(pos);
            }
        }

        int sum(int pos) {
            int res = 0;
            while (pos) {
                res += _tree[pos];
                pos -= lowbit(pos);
            }
            return res;
        }

        int sum(int a, int b) {
            return sum(b) - sum(a - 1);
        }
    private:
        inline int lowbit(int x) {
            return x & (-x);
        }
    private:
        vector<int> _tree;
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    int a, b;
    vector<pair<int, int> > points;
    BinaryIndexedTree bitree;
    
    input(n);
    bitree.init(n);
    
    set<int> xs;
    unordered_map<int, int> mapping_x;
    for (int i = 0; i < n; i++) {
        input(a >> b);
        points.push_back({a, b});
        xs.insert(a);
    }

    int idx = 1;
    for (auto iter = xs.begin(); iter != xs.end(); ++iter) {
        mapping_x[*iter] = idx++;
    }

    for (auto& point: points) {
        point.first = mapping_x[point.first];
        bitree.add(point.first, 1);
    }

    sort(points.begin(), points.end(),
            [](const pair<int, int>& pa, const pair<int, int>& pb) {
            return pa.second < pb.second;
            }
        );

    int p = 0;
    int q = 0;
    llint ans = 0;

    while (p < n) {
        while (q < n && points[p].second == points[q].second) {
            bitree.add(points[q].first, -1);
            q++;
        }
        ans += bitree.sum(points[p].first - 1);
        p++;
    }
    print(ans);
    return 0;
}



