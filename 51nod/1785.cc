#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <deque>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5555555;
const int INF = 0x3f3f3f3f;

typedef long long llint;

deque<int> dq;
multiset<int> stleft, stright;
llint sum;
llint sqsum;
int n, k;

void add(int v) {
    int pre = 0;
    if (dq.size() >= k) {
        pre = dq.front();
        dq.pop_front();
        
        if (stleft.find(pre) != stleft.end()) {
            auto iter = stleft.find(pre);
            stleft.erase(iter);
        } else if (stright.find(pre) != stright.end()) {
            auto iter = stright.find(pre);
            stright.erase(iter);
        }
    }

    if (stleft.empty() && stright.empty()) {
        stleft.insert(v);
    } else if (stleft.empty()) {
        stright.insert(v);
    } else if (stright.empty()) {
        stleft.insert(v);
    } else {
        if (v <= *stleft.rbegin()) {
            stleft.insert(v);
        } else {
            stright.insert(v);
        }
    }

    sum -= pre;
    sqsum -= pre * pre;
    dq.push_back(v);
    sum += v;
    sqsum += v * v;
}

double mean() {
    return sum / dq.size();
}

double standard_deviation() {
    double m = 1.0 * sum / dq.size();
    return (1.0 * sqsum / dq.size()) - (m * m);
}

double median() {
    int num = stleft.size() + stright.size();
    while (stleft.size() > stright.size() + 1) {
        int v = *stleft.rbegin();
        stright.insert(v);
        stleft.erase(stleft.find(v));
    }

    while (stright.size() > stleft.size()) {
        int v = *stright.begin();
        stleft.insert(v);
        stright.erase(stright.find(v));
    }

    if (num % 2 == 0) {
        double a = *stleft.rbegin();
        double b = *stright.begin();
        return (a + b) / 2;
    } else {
        return *stleft.rbegin();
    }
}

int main() {
    input(n >> k);
    int cmd, v;
    sum = sqsum = 0;
    while (n--) {
        scanf("%d", &cmd);
        switch(cmd) {
            case 1: {
                scanf("%d", &v);
                add(v);
            } break;
            
            case 2: {
                double ans = mean();
                printf("%.2f\n", ans);
            } break;

            case 3: {
                double ans = standard_deviation();
                printf("%.2f\n", ans);
            } break;

            case 4: {
                double ans = median();
                printf("%.2f\n", ans);
            } break;

            default: {
                assert(false);
            }
        } 
    }
    return 0;
}
