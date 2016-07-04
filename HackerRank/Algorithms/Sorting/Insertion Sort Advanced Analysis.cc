#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 111111;

class BITree {
    inline int lowbit(int x) { return x & -x; }
public:
    BITree(int n) {
        _n = n + 1;
        _array = vector<int>(n + 1, 0);
    }
    
    void add(int pos, int x) {
        while (pos < _n) {
            _array[pos] += x;
            pos += lowbit(pos);
        }
    }
    
    int sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
    
    int sum(int x) {
        int ans = 0;
        while (x) {
            ans += _array[x];
            x -= lowbit(x);
        }
        return ans;
    }
private:
    int _n;
    vector<int> _array;
};


int n;
vector<int> A;

int main() {
    int T;
    input(T);
    while (T--) {
        input(n);
        A = vector<int>(n, 0);
        map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            mp[A[i]] = -1;
        }
        
        int idx = 1;
        for (auto& p: mp) {
            p.second = idx++;
        }
        
        auto bitree = BITree(idx);
        for (auto& i: A) {
            i = mp[i];
        }
        
        llint ans = 0;
        for (int i = 0; i < n; i++) {
            ans += bitree.sum(A[i] + 1, idx);
            bitree.add(A[i], 1);
        }
        print(ans);
    }
    return 0;
}
