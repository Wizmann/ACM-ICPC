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

template <typename T>
void print(const vector<T>& vec) {
    cout << "[";
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << ", ";
        }
        cout << vec[i];
    }
    cout << "]\n";
}

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<pair<llint, llint> > st;
        for (auto num : nums) {
            if (num % 2 == 1) {
                st.insert({1LL * num, 2LL * num});
            } else {
                int u = num;
                while (u % 2 == 0) {
                    u /= 2;
                }
                st.insert({1LL * u, 1LL * num});
            }
        }

        llint res = INF;
        while (true) {
            auto minip = *st.begin();
            const auto& maxip = *st.rbegin();
            res = min(res, maxip.first - minip.first);

            if (minip.first != minip.second) {
                minip.first *= 2;
                st.erase(st.begin());
                st.insert(minip);
            } else {
                break;
            }
        }
        return res;
    }
};


