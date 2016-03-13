#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n, m;
vector<int> nums;

int main() {
    input(n >> m);
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    unordered_multiset<int> st0;
    unordered_set<int>      st1;
    queue<int> q;

    int maxi = -1;
    int p = -1;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        st0.insert(num);
        st1.insert(num);

        while (int(st1.size()) > m) {
            int idx = q.front();
            q.pop();
            int val = nums[idx];
            auto iter = st0.find(val);
            st0.erase(iter);
            iter = st0.find(val);
            if (iter == st0.end()) {
                st1.erase(st1.find(val));
            }
        }

        q.push(i);

        if (int(q.size()) > maxi) {
            maxi = q.size();
            p = i;
        }
    }

    print(p - maxi + 1 + 1 << ' ' << p + 1);
    return 0;
}
