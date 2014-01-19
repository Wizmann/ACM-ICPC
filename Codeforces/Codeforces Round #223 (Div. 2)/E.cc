// Result: Jan 14, 2014 6:50:45 PM  Wizmann  E - Sereja and Brackets     GNU C++0x  Accepted    249 ms  14500 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1000100;

struct ppair {
    int l, r;
    int id;
    
    ppair(){}
    ppair(int il, int ir, int iid): l(il), r(ir), id(iid) {}
    
    friend bool operator < (const ppair& a, const ppair& b) {
        return a.r < b.r;
    }
};

inline int lowbit(int x)
{
    return x&(-x);
}

struct BIT//点更新，区间查询
{
    int baum[SIZE];
    inline void init()
    {
        memset(baum,0,sizeof(baum));
    }
    void add(int x,int val)
    {
        while(x<SIZE)
        {
            baum[x]+=val;
            x+=lowbit(x);
        }
    }
    int sum(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=baum[x];
            x-=lowbit(x);
        }
        return res;
    }
    int sum(int a,int b)//查询区间和
    {
        return sum(b)-sum(a-1);
    }
};

int q;
char ss[SIZE];
vector<ppair> match;
vector<ppair> query;
vector<int> ans;

void preload()
{
    stack<int> st;
    for (int i = 0; ss[i]; i++) {
        char c = ss[i];
        if (c == '(') {
            st.push(i);
        } else if (c == ')' && !st.empty()) {
            int now = st.top();
            st.pop();
            match.push_back(ppair(now + 1, i + 1, -1));
        }
    }
}

void solve()
{
    sort(match.begin(), match.end());
    sort(query.begin(), query.end());
    ans.resize(query.size());
    BIT bit;
    bit.init();
    
    int p = 0;
    for (int i = 0; i < (int)query.size(); i++) {
        while (p < (int)match.size() && match[p].r <= query[i].r) {
            bit.add(match[p].l, 1);
            p++;
        }
        
        ans[query[i].id] = bit.sum(query[i].l, query[i].r);
    }
}    

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    scanf("%s", ss);
    preload();

    input(q);
    for (int i = 0; i < q; i++) {
        input(a >> b);
        query.push_back(ppair(a, b, i));
    }
    solve();
    for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
        print(*iter * 2);
    }
    return 0;
}

