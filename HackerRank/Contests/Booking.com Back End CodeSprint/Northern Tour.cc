#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 25;

vector<string> split_by_comma(const string& s) {
    vector<string> res;
    string tmp;
    int l = s.size();
    for (int i = 0; i <= l; i++) {
        if (i == l || s[i] == ',') {
            if (!tmp.empty()) {
                res.push_back(tmp);
                tmp = "";
            }
        } else {
            tmp += s[i];
        }
    }
    return res;
}

int atoi(string s) {
    int res = 0;
    for (auto c: s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

struct Node {
    int dest;
    int cost;
};

vector<Node> g[SIZE];
vector<int> stay;
int n, m;
int idx = 2;
unordered_map<string, int> mp;

char visit[SIZE];
vector<int> path;
vector<int> ans;
int maxi = 0;

int calc_next_tm(int tm, int cur_tm, int next_tm) {
    while (cur_tm) {
        if (tm % 24 <= 7) {
            tm += 8 - (tm % 24);
        }
        tm++;
        cur_tm--;
    }
    while (true) {
        while (tm % 24 <= 7) {
            tm++;
        }
        int t = tm;
        bool flag = true;
        for (int i = 0; i < next_tm; i++) {
            if (t % 24 <= 7) {
                tm++;
                flag = false;
                break;
            }
            t++;
        }
        if (flag) {
            //print(">>" << tm);
            tm = t;
            break;
        }
    }
    return tm;
}

void dfs(int cur, int cnt, int tm) {
    //print(cur << ' ' << tm);
    int cur_tm = stay[cur];
    int next_tm = calc_next_tm(tm, cur_tm, 0);
    if (next_tm > 6 * 24 + 8) {
        return;
    }
    
    visit[cur] = 1;
    
    path.push_back(cur);
    for (auto next: g[cur]) {
        if (!visit[next.dest]) {
            int cost = next.cost;
            int next_tm = calc_next_tm(tm, cur_tm, cost);
            dfs(next.dest, cnt + 1, next_tm);
        }
    }
    
    
    if (next_tm <= 6 * 24 + 8 && cnt > maxi) {
        maxi = cnt;
        ans = path;
    }
    path.pop_back();
    visit[cur] = 0;
}

int main() {   
    assert(calc_next_tm(8, 10, 10) == 18 + 24);
    assert(calc_next_tm(8, 0, 16) == 24);
    assert(calc_next_tm(8, 16, 16) == 48);
    assert(calc_next_tm(8, 10, 6) == 24);
    assert(calc_next_tm(0, 1, 1) == 10);
    assert(calc_next_tm(0, 15, 1) == 24);
    assert(calc_next_tm(0, 17, 1) == 34);
    
    
    string s;
    input(n);

    mp["Bevagna"] = 1;
    stay = vector<int>(SIZE, 0);
    for (int i = 0; i < n; i++) {
        input(s);
        auto v = split_by_comma(s);

        const auto& city = v[0];
        const auto& tm = atoi(v[1]);
        if (mp.find(city) == mp.end()) {
            mp[city] = idx++;
        }
        stay[mp[city]] = tm;
    }
    
    input(m);
    for (int i = 0; i < m; i++) {
        input(s);
        auto v = split_by_comma(s);
        int c1 = mp[v[0]];
        int c2 = mp[v[1]];
        int dis = atoi(v[2].c_str());

        if (dis > 16) {
            continue;
        }

        g[c1].push_back({c2, dis});
        g[c2].push_back({c1, dis});
    }
    memset(visit, 0, sizeof(visit));
    dfs(1, 1, 8);

    unordered_map<int, string> rmp;
    for (const auto& p: mp) {
        rmp[p.second] = p.first;
    }
    
    if (ans.size() == 1) {
        print("NONE");
    } else {
        for (auto item: ans) {
            if (item == 1) {
                continue;
            }
            print(rmp[item]);
        }
    }

    return 0;
}
