#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int l = 0;
        int r = int(1e9);
        sort(nums.begin(), nums.end());
        while (l <= r) {
            int m = (1LL * l + r) / 2;
            if (solve(nums, m, p)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    
    bool solve(vector<int>& nums, int maxi, int p) {
        int n = nums.size();
        int cur = 0;
        for (int i = 0; i < p; i++) {
            bool flag = false;
            while (cur + 1 < n) {
                if (nums[cur + 1] - nums[cur] <= maxi) {
                    flag = true;
                    cur = cur + 2;
                    break;
                } else {
                    cur++;
                }
            }
            if (!flag) {
                return false;
            }
        }
        return true;
    }
};
