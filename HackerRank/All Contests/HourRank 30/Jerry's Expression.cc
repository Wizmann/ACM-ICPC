#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Expr {
    Expr(int u) {
        pos = new list<int>();
        neg = new list<int>();
        pos->push_back(u);
    }

    list<int> *pos;
    list<int> *neg;

    void add(Expr& other) {
        pos->splice(pos->end(), *other.pos);
        neg->splice(neg->end(), *other.neg);
    }

    void minus(Expr& other) {
        pos->splice(pos->end(), *other.neg);
        neg->splice(neg->end(), *other.pos);
    }
};

void solve(const string& s) {
    int n = s.size();
    int idx = 0;
    stack<Expr> st;
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        if (c == '?') {
            st.push(Expr(idx++));
        } else if (c == '+') {
            auto a = st.top();
            st.pop();

            auto b = st.top();
            st.pop();

            a.add(b);
            st.push(a);
        } else if (c == '-') {
            auto a = st.top();
            st.pop();

            auto b = st.top();
            st.pop();

            a.minus(b);
            st.push(a);
        } else {
            assert(false);
        }
    }

    list<int>& pos = *st.top().pos;
    list<int>& neg = *st.top().neg;

    vector<int> res(idx, 1);
    int np = pos.size();
    int ng = neg.size();

    int tot = np - ng;

    if (tot > 0) {
        for (const auto& u: neg) {
            int v = tot / ng;
            tot -= v;
            res[u] += v;
            ng -= 1;
        }
    } else {
        tot = -tot;
        for (const auto& u: pos) {
            int v = tot / np;
            tot -= v;
            res[u] += v;
            np -= 1;
        }
    }

    for (int i = idx - 1; i >= 0; i--) {
        printf("%d\n", res[i]);
    }
}

int main() {
    string s;
    input(s);
    solve(s);
    return 0;
}
