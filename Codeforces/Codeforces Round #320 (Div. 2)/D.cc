#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int BITS = 64;

vector<int> bits;
vector<llint> nums;
int n, k;
llint x;

void init_bits() {
    for (auto num: nums) {
        for (int i = 0; i < BITS; i++) {
            if (num & (1LL << i)) {
                bits[i]++;
            }
        }
    }
}

void inc() {
    int idx = -1;
    llint sum = 0;
    for (int i = 0; i < BITS; i++) {
        sum |= (bits[i]? 1LL: 0LL) << i;
    }
    llint maxi = sum;

    for (int i = 0; i < n; i++) {
        llint u = nums[i];
        llint v = u * x;
        llint w = sum;

        for (int j = 0; j < BITS; j++) {
            bool a = (u & (1LL << j));
            bool b = (v & (1LL << j));
            bool c = (bits[j] > 1);

            if (a && !b && !c) {
                w ^= (1LL << j);
            }
            if (!a && b) {
                w |= (1LL << j);
            }
        }

        if (w > maxi) {
            maxi = w;
            idx = i;
        }
    }
    
    if (idx == -1) {
        return;
    }

    for (int i = 0; i < BITS; i++) {
        llint u = nums[idx];
        llint v = u * x;
        bool a = (u & (1LL << i));
        bool b = (v & (1LL << i));
        if (a && !b) {
            bits[i]--;
        }
        if (!a && b) {
            bits[i]++;
        }
    }

    nums[idx] *= x;
}


int main() {
    freopen("input.txt", "r", stdin);
    input(n >> k >> x);
    nums.resize(n);
    bits.resize(BITS);
    for (int i = 0; i < n; i++) {
        input(nums[i]);
    }
    init_bits();
    
    llint xx = 1;
    for (int i = 0; i < k; i++) {
        xx *= x;
    }
    x = xx;
    inc();

    llint ans = 0;
    for (int i = 0; i < BITS; i++) {
        ans |= (bits[i]? 1LL: 0LL) << i;
    }
    print(ans);
    return 0;
}
