// Result: wizmann	1182	Accepted	1308K	266MS	G++	1857B	2017-04-19 02:07:00
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Solution {
public:
    Solution(int n_, int k_): n(n_), k(k_) {
        father.resize(n * 3 + 100);
        for (int i = 0; i <= n * 3; i++) {
            father[i] = i;
        }
    }

    int solve() {
        int a, b, c;
        int ans = 0;
        while (k--) {
            scanf("%d%d%d", &a, &b, &c);
            if (b > n || c > n) {
                ans++;
                continue;
            }
            b--;
            c--;
            if (a == 1) {
                if (is_same(b * 3, c * 3 + 1) || is_same(b * 3, c * 3 + 2)) {
                    ans++;
                } else {
                    connect(b * 3, c * 3);
                    connect(b * 3 + 1, c * 3 + 1);
                    connect(b * 3 + 2, c * 3 + 2);
                }
            } else {
                
                if (is_same(b * 3, c * 3) || is_same(b * 3, c * 3 + 2)) {
                    ans++;
                    continue;
                }
                connect(b * 3, c * 3 + 1);
                connect(b * 3 + 1, c * 3 + 2);
                connect(b * 3 + 2, c * 3);
            }
        }
        return ans;
    }
private:
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

    bool is_same(int a, int b) {
        return find_father(a) == find_father(b);
    }

    void connect(int a, int b) {
        father[find_father(a)] = find_father(b);
    }
private:
    int n, k;
    vector<int> father;
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, k;
    input(n >> k);
    {
        Solution S(n, k);
        printf("%d\n", S.solve());
    }
    return 0;
}
