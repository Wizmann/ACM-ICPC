#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MOD = 1000000009;

string dbmap[] = {
    "0000",
    "0001", 
    "0010", 
    "0011", 
    "0100", 
    "0101", 
    "0110", 
    "0111", 
    "1000", 
    "1001"
};

template <int ALPHABET, int NODE_SIZE>
class ACAutomation {
public:
    void insert(const string& str, int nr) {
        int p = ROOT;
        for (int i = 0; i < str.size(); i++) {
            int c = str[i];
            if (!trie[p].next[c]) {
                trie[p].next[c] = ++tail;
                assert(tail < NODE_SIZE);
            }
            p=trie[p].next[c];
        }
        trie[p].frq++;
        trie[p].end=nr;
    }

    void makeAC() {
        queue<int> q;
        for (int i = 0; i < ALPHABET; i++) {
            if (trie[ROOT].next[i]) {
                trie[trie[ROOT].next[i]].fail = ROOT;
                q.push(trie[ROOT].next[i]);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i=0; i < ALPHABET; i++) {
                if (trie[p].next[i]) {
                    int v = trie[p].next[i];
                    q.push(v);
                    trie[v].fail = trie[trie[p].fail].next[i];
                } else {
                    trie[p].next[i] = trie[trie[p].fail].next[i];
                }
            }
        }
    }

    int find(int p, char c, vector<int>& matched) {
        while (trie[p].fail && !trie[p].next[c]) {
            p = trie[p].fail;
        }

        p = trie[p].next[c];
        int t = p;
        while (t) {
            if (trie[t].end) {
                matched.push_back(trie[t].end);
            }
            t = trie[t].fail;
        }
        return p;
    }

    void clear() {
        memset(trie, 0, sizeof(trie));
        tail = 0;
    }
private:
    struct node {
        int next[ALPHABET];
        int fail;
        int frq;
        int end; 
    };

    int tail = 0;
    node trie[NODE_SIZE];
public:
    const int ROOT = 0;
};


ACAutomation<128, 10000> ac;

string minus1(string num) {
    if (num == "1") {
        return "0";
    }
    reverse(num.begin(), num.end());
    int g = -1;
    for (int i = 0; i < num.size(); i++) {
        num[i] += g;
        g = 0;
        if (num[i] < '0') {
            num[i] = '9';
            g = -1;
        }
    }

    int n = num.size();
    if (num[n - 1] == '0') {
        num = string(num.c_str(), n - 1);
    }
    reverse(num.begin(), num.end());
    return num;
}

llint dp[222][12345];

llint dfs(const string& num, int p, int acp, bool st, bool lt) {
    int l = num.size() - p;
    llint& u = dp[l][acp];

    if (st && lt && u != -1) {
        return u;
    }

    if (l == 0) {
        return 1;
    }

    llint res = 0;
    int cur = num[p];
    for (int i = 0; i < (lt? 10: cur + 1); i++) {
        bool nst = true;
        if (st == false && i == 0) {
            nst = false;
        }

        vector<int> matched;
        int nacp = acp;
        if (nst == true) {
            for (int j = 0; j < dbmap[i].size(); j++) {
                nacp = ac.find(nacp, dbmap[i][j] - '0', matched);
            }
        }
        if (!matched.empty()) {
            continue;
        }

        res += dfs(num, p + 1, nacp, nst, lt || i < cur);
        res %= MOD;
    }

    if (st && lt) {
        return u = res;
    } else {
        return res;
    }
}

llint solve(const string& num) {
    return dfs(num, 0, 0, false, false);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    assert(minus1("123") == "122");
    assert(minus1("1000") == "999");
    assert(minus1("1") == "0");
    assert(minus1("9") == "8");

    ac.insert("10", 1);
    vector<int> matched;

    ac.makeAC();

    int p = 0;
    p = ac.find(p, '1', matched);
    assert(matched.empty());
    p = ac.find(p, '1', matched);
    assert(matched.empty());
    p = ac.find(p, '0', matched);
    assert(!matched.empty());

    int n;
    while (T--) {
        memset(dp, -1, sizeof(dp));
        input(n);

        ac.clear();

        char buffer[22];
        for (int i = 1; i <= n; i++) {
            scanf("%s", buffer);
            string str(buffer);
            for (int j = 0; j < str.size(); j++) {
                str[j] -= '0';
            }
            ac.insert(str, i);
        }

        char numA[222];
        char numB[222];

        scanf("%s%s", numA, numB);

        string strA(numA);
        string strB(numB);

        strA = minus1(strA);

        for (int i = 0; i < strA.size(); i++) {
            strA[i] -= '0';
        }

        for (int i = 0; i < strB.size(); i++) {
            strB[i] -= '0';
        }

        ac.makeAC();

        llint b = solve(strB);
        llint a = solve(strA);

        print(((b - a) % MOD + MOD) % MOD);
    }
    return 0;
}
