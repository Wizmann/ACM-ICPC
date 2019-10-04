#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 15 * 100 + 123;
const int N = 15;
const int SIZE = (1 << 15) + 13;

int n;
short dp[N][SIZE];
short pdp[N][SIZE];
short g[N][N];
vector<string> strs;

int dfs(int cur, int status) {
    if (dp[cur][status] < INF) {
        return dp[cur][status];
    }

    if (status == 0) {
        return 0;
    }

    int res = INF;
    string ss;
    int pre = -1;
    for (int i = 0; i < n; i++) {
        if (!(status & (1 << i))) {
            continue;
        }
        int delta = g[cur][i];
        string ts = strs[i].substr(strs[i].size() - delta);
        int nxt = dfs(i, status ^ (1 << i)) + delta;
        if (nxt < res) {
            res = nxt;
            pre = i;
            ss = ts;
        } else if (nxt == res && strcmp(ts.c_str(), ss.c_str()) < 0) {
            pre = i;
            ss = ts;
        }
    }

    pdp[cur][status] = pre;
    // print(cur << ' ' << status << ' ' << pre);
    return dp[cur][status] = res;
}

bool do_compare(const std::string& sa, const std::string& sb, int k) {
    int la = sa.size();
    int lb = sb.size();

    int pa = sa.size() - k;
    int pb = 0;

    for (int i = 0; i < k; i++) {
        if (sa[pa] != sb[pb]) {
            return false;
        }
        pa++;
        pb++;
    }
    return true;
}

int main() {
    int T;
    input(T);

    char buffer[111];
    int case_ = 0;

    while (T--) {
        scanf("%d", &n);
        int a, b;
        strs.clear();
        set<string> stbuffer;
        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            stbuffer.insert(buffer);
        }

        for (set<string>::iterator iter = stbuffer.begin(); iter != stbuffer.end(); ++iter) {
            strs.push_back(*iter);
        }
        n = strs.size();

        vector<string> ss;
        for (int i = 0; i < n; i++) {
            const string& sa = strs[i];
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                const string& sb = strs[j];
                if (sb.find(sa) != string::npos) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                ss.push_back(sa);
            }
        }

        strs = ss;
        n = strs.size();

        memset(g, INF, sizeof(INF));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                g[i][j] = strs[j].size();

                int la = strs[i].size();
                int lb = strs[j].size();
                for (int k = min(la, lb); k >= 0; k--) {
                    if (do_compare(strs[i], strs[j], k) == true) {
                        g[i][j] = lb - k;
                        // print(i << ' ' << j << ' ' << k);
                        break;
                    }
                }
            }
        }

        memset(dp, INF, sizeof(dp));
        memset(pdp, -1, sizeof(pdp));

        int st = -1;
        int res = INF;
        for (int i = 0; i < n; i++) {
            int t = dfs(i, ((1 << n) - 1) ^ (1 << i)) + int(strs[i].size());
            if (t < res) {
                res = t;
                st = i;
            }
        }
        printf("Scenario #%d:\n", ++case_);

        string s;
        int pre = -1;
        int status = (1 << n) - 1;
        for (int j = 0; j < n; j++) {
            if (pre == -1) {
                s += strs[st];
            } else {
                s += strs[st].substr(strs[st].size() - g[pre][st]);
            }
            status ^= (1 << st);
            pre = st;
            st = pdp[st][status];
            // assert(st != -1);
        }
        assert (status == 0);
        puts(s.c_str());
        puts("");
    }
    return 0;
}
