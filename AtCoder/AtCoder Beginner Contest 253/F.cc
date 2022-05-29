#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;
typedef long long LL;
     
const int INF=0x3f3f3f3f;
 
const int N= 212345;

const int PTREE_SIZE = N * 99;
 
struct Node
{
    int l,r;
    LL sum,lazy;
}tree[PTREE_SIZE];
 
int cnt,root[N];
 
void build(int &k,int l,int r)
{
    k=cnt++;
    tree[k].lazy=0;
    if(l==r)
    {
        tree[k].sum = 0;
        return;
    }
    int mid=(l+r)>>1;
    build(tree[k].l,l,mid);
    build(tree[k].r,mid+1,r);
    tree[k].sum=tree[tree[k].l].sum+tree[tree[k].r].sum;
}
 
void update(int &k,int l,int r,int L,int R,LL val) //[l,r]:目标区间 [L,R]:当前区间
{
    tree[cnt++]=tree[k];
    assert(cnt < PTREE_SIZE);
    k=cnt-1;
    tree[k].sum+=val*(r-l+1);
    if(L>=l&&R<=r)
    {
        tree[k].lazy+=val;
        return;
    }
    int mid=(L+R)>>1;
    if(r<=mid)
        update(tree[k].l,l,r,L,mid,val);
    else if(l>mid)
        update(tree[k].r,l,r,mid+1,R,val);
    else
    {
        update(tree[k].l,l,mid,L,mid,val);
        update(tree[k].r,mid+1,r,mid+1,R,val);
    }
}
 
LL query(int k,int l,int r,int L,int R,LL add) //[l,r]:目标区间 [L,R]:当前区间
{
    if(R<l||L>r)
        return 0;
    if(L>=l&&R<=r)
        return tree[k].sum+add*(R-L+1);
    int mid=(L+R)>>1;
    return query(tree[k].l,l,r,L,mid,add+tree[k].lazy)+query(tree[k].r,l,r,mid+1,R,add+tree[k].lazy);
}
 
int main() {
    int n,m,q;
    scanf("%d%d%d", &n, &m, &q);

    cnt=1;
    build(root[0],1,m);
    int time=0;
    int cmd = 0;
    vector<int> assign_value(n + 1, 0);
    vector<int> assign_time(n + 1, 0);
    for (int i = 0; i < q; i++) {
        scanf("%d", &cmd);
        time++;
        root[time]=root[time-1];
        if (cmd == 1) {
            int l,r,d;
            scanf("%d%d%d",&l,&r,&d);
            update(root[time],l,r,1,m,d);
        } else if (cmd == 2) {
            int idx, y;
            scanf("%d%d", &idx, &y);
            assign_value[idx] = y;
            assign_time[idx] = i;
        } else if (cmd == 3) {
            int y, x;
            scanf("%d%d", &y, &x);

            llint base = assign_value[y];
            llint v1 = query(root[time], x, x, 1, m, 0);
            llint v2 = query(root[assign_time[y]], x, x, 1, m, 0);

            printf("%lld\n", base + v1 - v2);
        }
    }
 
 
    return 0;
}

/*
^^^^TEST^^^^
3 3 9
1 1 2 1
3 2 2
2 3 2
3 3 3
3 3 1
1 2 3 3
3 3 2
3 2 3
3 1 2
-------
1
2
2
5
3
4
$$$$TEST$$$$

^^^^^TEST^^^
1 1 10
1 1 1 1000000000
1 1 1 1000000000
1 1 1 1000000000
1 1 1 1000000000
1 1 1 1000000000
1 1 1 1000000000
1 1 1 1000000000
1 1 1 1000000000
1 1 1 1000000000
3 1 1
-------
9000000000
$$$$TEST$$$
^^^^TEST^^^^
10 10 10
1 1 8 5
2 2 6
3 2 1
3 4 7
1 5 9 7
3 3 2
3 2 8
2 8 10
3 8 8
3 1 10
------
6
5
5
13
10
0
$$$$TEST$$$$


*/

