#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024;

vector<int> nums;
int n;

int solve() {
    int res = 1;
    unordered_map<int, int> mp;
    for (int i = 1; i < SIZE; i++) {
        int cnt = 0;
        for (auto num: nums) {
            if (num % i == 0) {
                cnt++;
            } else {
                continue;
            }
            int a = i;
            int b = num / a;
            
            if (a <= b) {
                mp[a]++;
                mp[b]++;
            }
        }
    }
    
    for (auto p: mp) {
        if (p.second > 1) {
            res = max(res, p.first);
        }
    }
    
    return res;
}

int main() {
    int x;
    input(n);
    for (int i = 0; i < n; i++) {
        input(x);
        nums.push_back(x);
    }
    print(solve());
    return 0;
}
