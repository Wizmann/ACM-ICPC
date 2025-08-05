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

struct Interval {
    int l, r;
    
    bool operator < (const Interval& other) const {
        return r < other.l;
    }    
};

class IntervalList {
public:
    IntervalList() = default;
    
    int get_max() {
        if (st.empty()) {
            return -1;
        }
        return *st.rbegin();
    }
    
    void insert(int l, int r) {
        Interval interval = {l, r};
        
        if (intervals.find(interval) == intervals.end()) {
            intervals.insert(interval);
            st.insert(r - l);
            return;
        }
        
        auto it = intervals.find(interval);
        st.erase(st.find(it->r - it->l));
        int ll = it->l;
        int rr = it->r;
        
        intervals.erase(it);
        insert(min(l, ll), max(r, rr));
    }
    
    void remove(int x) {
        auto it = intervals.find(Interval{x, x + 1});
        int l = it->l;
        int r = it->r;
        intervals.erase(it);
        st.erase(st.find(r - l));
        
        if (x > l) {
            intervals.insert(Interval{l, x});
            st.insert(x - l);
        }
        if (r > x + 1) {
            intervals.insert(Interval{x + 1, r});
            st.insert(r - (x + 1));
        }
    }
private:
    set<Interval> intervals;
    multiset<int> st;
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<IntervalList> intervals(26);
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            intervals[c].insert(i, i + 1);
        }
        
        auto get_max = [&]() {
            int maxi = 0;
            for (int i = 0; i < 26; i++) {
                maxi = max(maxi, intervals[i].get_max());
            }
            return maxi;
        };
        
        vector<int> res;
        int m = queryCharacters.size();
        for (int i = 0; i < m; i++) {
            int p = queryIndices[i];
            int pre = s[p] - 'a';
            int cur = queryCharacters[i] - 'a';
            
            intervals[pre].remove(p);
            intervals[cur].insert(p, p + 1);

            res.push_back(get_max());
            s[p] = queryCharacters[i];
        }
        
        return res;
    }
};

