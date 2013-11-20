//Result: Nov 15, 2013 6:16:12 PM   Wizmann  D - Fools and Foolproof Roads   GNU C++    Accepted     296 ms  9500 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 100100;
const llint INF = 1000000000LL;

struct Road {
    int from, to;
    llint cost;
    Road(){}
    Road(int ifrom, int ito, llint icost): \
            from(ifrom), to(ito), cost(icost) {}
};

struct Distinct {
    int nr;
    llint tot;
    Distinct(){}
    Distinct(int inr, llint itot): \
            nr(inr), tot(itot){}

    friend bool operator < (const Distinct& a, const Distinct& b)
    {
        return a.tot > b.tot;
    }
};

int n, m, p ,q;
vector<Road> road_vec, new_road_vec;
int cnc[SIZE];
llint rlen[SIZE];

void init()
{
    road_vec.clear();
    new_road_vec.clear();
    for (int i = 0; i < SIZE; i++) {
        cnc[i] = i;
    }
    memset(rlen, 0, sizeof(rlen));
}

int get_father(int x)
{
    if (cnc[x] == x) return x;
    else return cnc[x] = get_father(cnc[x]);
}

int make_union()
{
    for (int i = 0;i < (int)road_vec.size(); i++) {
        int from = road_vec[i].from;
        int to = road_vec[i].to;
        cnc[get_father(from)] = cnc[get_father(to)];
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(get_father(cnc[i]));
    }
    return st.size();
}

void fill_rlen()
{
    for (int i = 0; i < (int)road_vec.size(); i++) {
        int from = road_vec[i].from;
        int cost = road_vec[i].cost;
        rlen[get_father(from)] += cost;
    }
}

llint solve()
{
    llint res = 0;
    priority_queue<Distinct> pq;
    for (int i = 0; i < n; i++) {
        if (get_father(i) != i) continue;
        else {
            pq.push(Distinct(i, rlen[i]));
        }
    }
    for (int i = 0; i < p && pq.size() >= 2; i++) {
        Distinct a = pq.top();
        pq.pop();
        Distinct b = pq.top();
        pq.pop();
        llint cost = min(INF, a.tot + b.tot + 1);
        res += cost;
        new_road_vec.push_back(Road(a.nr, b.nr, -1));
        Distinct c(a.nr, a.tot + b.tot + cost);
        pq.push(c);
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    llint c;
    while(input(n >> m >> p >> q)) {
        init();
        while (m--) {
            input(a >> b >> c);
            a--;b--;
            road_vec.push_back(Road(a, b, c));
        }
        int us = make_union();
        fill_rlen();
        if (us - p > q || us < q) {
            print("NO");
            continue;
        } 
        llint ans = 0;
        int t = 0;
        bool need_fill = false;
        Road road_fill;
        if (us - p < q) {
            t = p - (us - q); 
            p = us - q;
            need_fill = true;
        }
        ans += solve();
        if (need_fill && \
                road_vec.empty() &&
                new_road_vec.empty()) {
            print("NO");
            continue;
        } else if (need_fill) {
            road_fill = !road_vec.empty()? road_vec[0]: new_road_vec[0];
        }
        print("YES");
        
        for (int i = 0; i < t; i++) {
            new_road_vec.push_back(road_fill);
        }
        ans += 1000 * t;
        for (int i = 0; i < (int)new_road_vec.size(); i++) {
            printf("%d %d\n", 
                    new_road_vec[i].from + 1, 
                    new_road_vec[i].to + 1);
        }
        //print(ans);
    }
    return 0;
}

