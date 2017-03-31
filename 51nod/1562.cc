#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

char readchar() {
    char ch = ' ';
    while (!isalnum(ch)) {
        ch = getchar();
    }
    return ch;
}

int readint()
{
    char ch = ' ';
    int ans = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        ans=ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}

void printint(int x)
{
    if(x > 9) {
        printint(x / 10);
    }
    putchar(x % 10 + '0');
}

void printllint(llint x)
{
    if(x > 9) {
        printllint(x / 10);
    }
    putchar(x % 10 + '0');
}

class Edge {
public:
    Edge(const vector<int>& segs) {
        int n = segs.size();
        for (int i = 0; i < n - 1; i++) {
            int l = segs[i];
            int r = segs[i + 1];

            upper[r] = r - l;
            lower[l] = r - l;
            segset.insert(r - l);
        }
    }

    int max_seg() {
        if (segset.empty()) {
            return -1;
        }
        return *segset.rbegin();
    };

    int merge(int pos) {
        int l = upper[pos];
        int r = lower[pos];

        if (l == 0 || r == 0) {
            return -1;
        }

        segset.erase(segset.find(l));
        segset.erase(segset.find(r));
        segset.insert(l + r);

        upper.erase(upper.find(pos));
        lower.erase(lower.find(pos - l));

        lower.erase(lower.find(pos));
        upper.erase(upper.find(pos + r));

        upper[pos + r] = l + r;
        lower[pos - l] = l + r;

        return 0;
    }
private:
    map<int, int> upper, lower;
    multiset<int> segset;
};

void test() {
    vector<int> segs = {0, 1, 2, 3, 4};
    Edge e(segs);

    assert(e.max_seg() == 1);
    assert(e.merge(1) == 0);
    assert(e.merge(1) == -1);

    assert(e.max_seg() == 2);
    assert(e.merge(3) == 0);

    assert(e.max_seg() == 2);
    assert(e.merge(2) == 0);

    assert(e.max_seg() == 4);
}


int main() {
    int w = readint();
    int h = readint();
    int q = readint();

    vector<int> ws = {0, w};
    vector<int> hs = {0, h};
    vector<pair<char, int> > qs;

    ws.reserve(q);
    hs.reserve(q);
    qs.reserve(q);

    char cmd;
    int val;
    for (int i = 0; i < q; i++) {
        cmd = readchar();
        val = readint();
        qs.push_back({cmd, val});
        if (cmd == 'H') {
            hs.push_back(val);
        } else {
            ws.push_back(val);
        }
    }

    sort(ws.begin(), ws.end());
    sort(hs.begin(), hs.end());

    Edge hedge(hs);
    Edge wedge(ws);
    vector<llint> ans;
    ans.reserve(q);
    
    for (auto iter = qs.rbegin(); iter != qs.rend(); ++iter) {
        ans.push_back(1LL * hedge.max_seg() * wedge.max_seg());

        if (iter->first == 'H') {
            hedge.merge(iter->second);
        } else {
            wedge.merge(iter->second);
        }
    }

    for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter) {
        printllint(*iter);
        putchar('\n');
    }

    return 0;
}
