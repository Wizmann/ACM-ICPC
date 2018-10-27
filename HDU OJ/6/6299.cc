#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

char buffer[SIZE];

struct Node {
    int l, r;
    string s;

    Node(const int l_, const int r_, const string& s_) {
        l = l_;
        r = r_;
        s = s_;
    }

    bool operator < (const Node& other) {
        if (min(l, other.r) != min(r, other.l)) {
            return min(l, other.r) > min(r, other.l);
        }
        return l > other.l;
    }
};

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);
    while (T--) {
        int n;
        vector<Node> s;

        input(n);
        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            int l = 0;
            int r = 0;
            int cnt = 0;
            for (int j = 0; buffer[j]; j++) {
                if (buffer[j] == '(') {
                    l++;
                } else {
                    if (l > 0) {
                        l--;
                        cnt++;
                    } else {
                        r++;
                    }
                }
            }
            s.push_back(Node(l, r, string(buffer)));
        }

        sort(s.begin(), s.end());

        int res = 0;
        int l = 0;
        int r = 0;

        for (int i = 0; i < n; i++) {
            const string& cur = s[i].s;
            for (int j = 0; j < cur.size(); j++) {
                if (cur[j] == '(') {
                    l++;
                } else {
                    if (l > 0) {
                        res += 2;
                        l--;
                    }
                }
            }
        }
        print(res);
    }
    return 0;
}
