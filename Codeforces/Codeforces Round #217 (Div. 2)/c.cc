#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 128;

struct node {
    int color, num;
    node(){}
    node(int icolor, int inum) : color(icolor), num(inum) {}

    friend bool operator < (const node& a, const node& b) {
        return a.num < b.num;
    }
};

int n, m;
int color[SIZE];

int main()
{
    freopen("input.txt", "r", stdin);
    int x;
    while (input(n >> m)) {
        memset(color, 0, sizeof(color));
        for (int i = 0; i < n; i++) {
            input(x);
            color[x]++;
        }
        vector<node> vec;
        for (int i = 1; i <= m; i++) {
            vec.push_back(node(i, color[i]));
        }

        sort(vec.begin(), vec.end());

        vector<pair<int, int> > ans;

        for (int i = 0; i < (int)vec.size() - 1; i++) {
            int t = vec[i].num;
            for (int j = 0; j < t; j++) {
                ans.push_back(make_pair<int, int>(vec[i].color, vec[i + 1].color));
                ans.push_back(make_pair<int, int>(vec[i + 1].color, vec[i].color));
            }
            vec[i+1].num -= t;
        }
        int d = vec[m - 1].num * 2;
        int dc = vec[m - 1].color;

        int anssz = ans.size();
        for (int j = 0; j < anssz; j++) {
            if (d == 0) break;
            
            if (ans[j].first == dc || ans[j].second == dc) continue;
            int tc = ans[j].first;
            ans[j].first = dc;
            ans.push_back(make_pair<int, int>(tc, dc));
            d-=2;
        }
        print (ans.size());

        for (int i = 0; i < d; i+=2) {
            ans.push_back(make_pair<int, int>(dc, dc));
        }

        for (int i = 0; i < (int)ans.size(); i++) {
            print(ans[i].first << ' ' << ans[i].second);
        }
    }
    return 0;
}

