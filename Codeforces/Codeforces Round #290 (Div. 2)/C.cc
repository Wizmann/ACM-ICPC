#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 26;

vector<string> names;
vector<int> g[SIZE];
vector<int> res;
int n;
int in[SIZE];

bool makeG() {
    for (int i = 1; i < n; i++) {
        const string& pre = names[i - 1];
        const string& now = names[i];
        
        int len = min(pre.size(), now.size());
        
        if (pre.size() > now.size() && pre.substr(0, len) == now) {
            return false;
        }

        for (int j = 0; j < len; j++) {
            if (pre[j] == now[j]) {
                continue;
            }
            int a = pre[j] - 'a';
            int b = now[j] - 'a';
            g[a].push_back(b);
            in[b]++;
            break;
        }
    }
    return true;
}

bool top_sort() {
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) {
        if (in[i] == 0) {
            q.push(i);
            cnt++;
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        res.push_back(now);
        for (auto next: g[now]) {
            in[next]--;
            if (in[next] == 0) {
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt == SIZE;
}

void print_res() {
    for (auto i: res) {
        printf("%c", 'a' + i);
    }
    puts("");
}

int main() {
    string name;

    input(n);
    memset(in, 0, sizeof(in));
    for (int i = 0; i < n; i++) {
        input(name);
        names.push_back(name);
    }

    if (makeG() && top_sort()) {
        print_res();
    } else {
        puts("Impossible");
    }

    return 0;
}