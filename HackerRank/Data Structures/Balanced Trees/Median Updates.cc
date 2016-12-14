#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

class MedianSet {
public:
    MedianSet() {
        // pass
    }
    
    bool remove(int value, pair<int, int>& res) {
        auto iterL = left.find(value);
        auto iterR = right.find(value);
        
        if (iterL != left.end()) {
            left.erase(iterL);
        } else if (iterR != right.end()) {
            right.erase(iterR);
        } else {
            return false;
        }

        if (left.empty() && right.empty()) {
            return false;
        }
        
        adjust();
        res = get_median();
        return true;
    }
    
    bool append(int value, pair<int, int>& res) {
        if (left.empty() || value <= *left.rbegin()) {
            left.insert(value);
        } else {
            right.insert(value);
        }
        adjust();
        res = get_median();
        return true;
    }
private:
    void adjust() {
        while (left.size() > right.size() + 1) {
            int v = *left.rbegin();
            right.insert(v);
            left.erase(left.find(v));
        }

        while (right.size() > left.size()) {
            int v = *right.begin();
            left.insert(v);
            right.erase(right.find(v));
        }
    }

    pair<int, int> get_median() {
        if (left.size() > right.size()) {
            return {*left.rbegin(), *left.rbegin()};
        } else {
            return {*left.rbegin(), *right.begin()};
        }
    }
private:
    multiset<int> left, right;
};

int main(){    
    int n;
    input(n);
    
    char cmd[100];
    int x;

    MedianSet ms;
    
    for (int i = 0; i < n; i++) {
        scanf("%s%d", cmd, &x);
        pair<int, int> res;
        if (cmd[0] == 'r') {
            if (!ms.remove(x, res)) {
                print("Wrong!");
                continue;
            }
        } else if (cmd[0] == 'a') {
            if (!ms.append(x, res)) {
                print("Wrong!");
                continue;
            }
        }
        if (res.first == res.second) {
            printf("%d\n", res.first);
        } else {
            llint sum = 0LL + res.first + res.second;
            if (sum % 2 == 0) {
                printf("%lld\n", sum / 2);
            } else {
                printf("%.1f\n", 0.5 * sum);
            }
        }
    }
    
    return 0;
}

