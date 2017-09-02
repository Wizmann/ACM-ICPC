#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Entry {
    int cnt, num;
    
    bool operator < (const Entry& other) const {
        if (cnt != other.cnt) {
            return cnt < other.cnt;
        } else {
            return num > other.num;
        }
    }
};

int n, k;
deque<int> dq;
unordered_map<int, int> mp;
priority_queue<Entry> pq;

int main() {
    input(n >> k);
    
    int cmd, arg;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &arg);
            if (dq.size() < k) {
                dq.push_back(arg);
                mp[arg]++;
                pq.push({mp[arg], arg});
            } else {
                mp[*dq.begin()]--;
                pq.push({mp[*dq.begin()], *dq.begin()});
                dq.pop_front();
                mp[arg]++;
                pq.push({mp[arg], arg});
                dq.push_back(arg);
            }
        } else {
            while (!pq.empty()) {
                auto cur = pq.top();
                if (cur.cnt == mp[cur.num]) {
                    printf("%d\n", cur.num);
                    break;
                } else {
                    pq.pop();
                }
            }
        }
    }
    return 0;
}
