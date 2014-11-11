#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

string get_ans(const map<int, int>& mp, int x, int n) {
    string res;
    while (true) {
        int prev = mp.find(x)->second;
        if (prev == -1) {
            break;
        }
        if ((10LL * prev + 1) % n == x) {
            res = "1" + res;
        } else {
            res = "0" + res;
        }
        x = prev;
    }
    return "1" + res;
}

string get_ans(const map<int, int>& mp, int x, int y, int n, int cnt) {
    string res;
    if (x != 0) {
        string t = get_ans(mp, x, n);
        for (size_t i = t.length(); i < cnt; i++) {
            t = "0" + t;
        }
        res += t;
    }
    // res += "|";
    if (y != 0) {
        string t = get_ans(mp, y, n);
        for (size_t i = t.length(); i < cnt; i++) {
            t = "0" + t;
        }
        res += t;
    } else {
        for (int i = 0; i < cnt; i++) {
            res = res + "0";
        }
    }
    return res.substr(res.find_first_not_of("0"));
}

string solve(int n) {
    switch(n) {
        case 1:
            return "1";
        case 2: case 5: case 10:
            return "10";
    }
    vector<int> dp[2];
    int ptr = 0;
    map<int, int> mp;

    dp[ptr].push_back(1);    
    mp[1] = -1;

    int zehn = 10; // zehn is 10 in German
    int cnt = 1;

    while (true) {
        int next = ptr ^ 1;
        dp[next].clear();
        for (size_t i = 0; i < dp[ptr].size(); i++) {
            int x = dp[ptr][i];
            int xa = (10LL * dp[ptr][i]) % n;
            int xb = (10LL * dp[ptr][i] + 1) % n;

            if (mp.find(xa) == mp.end()) {
                mp[xa] = x;
                dp[next].push_back(xa);
            }
            if (mp.find(xb) == mp.end()) {
                mp[xb] = x;
                dp[next].push_back(xb);
            }
        }

        zehn = (10LL * zehn) % n;
        cnt++;
        
        for (size_t i = 0; i < dp[ptr].size(); i++) {
            int x = (1LL * zehn * dp[ptr][i]) % n;
            int y = (n - x) % n;
            
            if (x == 0) {
                return get_ans(mp, dp[ptr][i], 0, n, cnt);
            } else if (mp.find(y) != mp.end()) {
                return get_ans(mp, dp[ptr][i], y, n, cnt);
            }
        }

        for (size_t i = 0; i < dp[next].size(); i++) {
            int x = (1LL * zehn * dp[next][i]) % n;
            int y = (n - x) % n;
            
            if (x == 0) {
                return get_ans(mp, dp[next][i], 0, n, cnt);
            } else if (mp.find(y) != mp.end()) {
                return get_ans(mp, dp[next][i], y, n, cnt);
            }
        }
        ptr = next;
    }
    return "fuck me";
}

int main()
{
    int n;
    while (input(n)) {
        print(solve(n));
    }
    return 0;
}

