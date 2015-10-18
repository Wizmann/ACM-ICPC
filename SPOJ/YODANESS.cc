#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

unordered_map<string, int> mp;
int idx;
int n;

vector<int> A;

int reverse_number(vector<int>::iterator begin, vector<int>::iterator end) {
    int len = distance(begin, end);
    if (len <= 1) {
        return 0;
    }
    auto mid = begin + len / 2;
    
    int a = reverse_number(begin, mid);
    int b = reverse_number(mid, end);
    
    int cnt = a + b;
    vector<int> res;
    
    auto iter_i = begin, iter_j = mid;
    for (/* pass */; iter_i != mid && iter_j != end; /* pass */) {
        if (*iter_i < *iter_j) {
            res.push_back(*iter_i);
            ++iter_i;
        } else {
            res.push_back(*iter_j);
            cnt += distance(iter_i, mid);
            ++iter_j;
        }
    }
    
    while (iter_i != mid) {
        res.push_back(*iter_i++);
    }
    while (iter_j != end) {
        res.push_back(*iter_j++);
    }
    
    for (int i = 0; i < len; i++) {
        *(begin + i) = res[i];
    }
      
    return cnt;
}

int solve() {
    return reverse_number(A.begin(), A.end());
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    string s;

    while (T--) {
        idx = 0;
        mp.clear();
        A.clear();

        input(n);
        for (int i = 0; i < n; i++) {
            input(s);
            mp[s] = idx++;
        }

        for (int i = 0; i < n; i++) {
            input(s);
            idx = mp[s];
            A.push_back(idx);
        }

        print(solve());
    }
    return 0;
}
