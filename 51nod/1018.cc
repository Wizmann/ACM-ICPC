#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<int> vec;
int n;

template<typename Iter>
void mysort(Iter st, Iter end) {
    if (st >= end) {
        return;
    }
    int n = distance(st, end);
    int pivot_idx = rand() % n;
    int pivot = *(st + pivot_idx);
    iter_swap(st, st + pivot_idx);
    
    int cnt = 0;
    Iter l = st;
    Iter r = end - 1;
    
    while (l <= r) {
        while (l <= r && 
                (*l < pivot || (*l == pivot && cnt % 2 == 0))) {
            l++;
            cnt += (*l == pivot);
        }
        while (l <= r && 
                (*r > pivot || (*r == pivot && cnt % 2 == 1))) {
            r--;
            cnt += (*r == pivot);
        }
        if (l <= r) {
            iter_swap(l, r);
            l++;
            r--;
        }
    }
    iter_swap(st, r);
    mysort(st, r);
    mysort(r + 1, end);
}

int main() {
    int x;
    vec.reserve(50000);
    srand(time(nullptr));
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        vec.push_back(x);
    }
    mysort(vec.begin(), vec.end());
    for (auto i: vec) {
        print(i);
    }
    return 0;
}
