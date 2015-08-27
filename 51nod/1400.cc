#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 42;

char visit[SIZE];
vector<int> vec_a;
vector<int> vec_b;

bool check(const vector<int>& vec) {
    auto iter = vec_a.begin();
    vec_b.clear();
    for (int i = 0; i < vec.size(); i++) {
        if (visit[i]) {
            continue;
        }
        if (iter != vec_a.end() && vec[i] != *iter) {
            return false;
        }
        vec_b.push_back(vec[i]);
        if (iter != vec_a.end()) {
            ++iter;
        }
    }
    return true;
}
        

bool dfs(const vector<int>& vec, int ptr, int n) {
    if (ptr == n) {
        check(vec);
        return vec_a == vec_b;
    }
    if (vec_a.size() > n / 2) {
        return false;
    }
    if (vec_a.size() + (n - ptr) < n / 2) {
        return false;
    }
    for (int i = ptr; i < n; i++) {
        vec_a.push_back(vec[i]);
        visit[i] = 1;
        if (check(vec)) {
            if (dfs(vec, i + 1, n)) {
                return true;
            }
        }
        visit[i] = 0;
        vec_a.pop_back();
    }
    return false;
}

bool solve(const vector<int>& vec) {
    return dfs(vec, 0, vec.size());
}

int main() {
    freopen("input.txt", "r", stdin);
    int T, n, x;
    input(T);
    while (T--) {
        vector<int> vec;
        memset(visit, 0, sizeof(visit));
        vec_a.clear();
        vec_b.clear();
        input(n);
        for (int i = 0; i < n; i++) {
            input(x);
            vec.push_back(x);
        }
        if (solve(vec)) {
            print("Good job!!");
        } else {
            print("What a pity!");
        }
    }
    return 0;
}
