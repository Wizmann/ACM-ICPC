//Result:wizmann	2482	Accepted	4132K	516MS	G++	3549B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;
typedef unsigned uint;

const int SIZE = 10240;
const int INF = 1<<28;
const int ROOT = 0;

inline int left(int x){return 2*x+1;}
inline int right(int x){return 2*x+2;}

struct star
{
    llint x,y;
    int c;
    star(){}
    star(llint ix,llint iy,int ic)
    {
        x=ix;y=iy;c=ic;
    }
};

struct scanl
{
    llint a,b,pos;
    int c;
    
    scanl(){}
    scanl(llint ipos, llint ia, llint ib, int ic)
    {
        pos = ipos;
        a = ia; b = ib; c = ic;
    }
    
    friend bool operator < (const scanl& x, const scanl& y)
    {
        if(x.pos != y.pos) return x.pos < y.pos;
        else return x.c > y.c;
    }
};

struct node
{
    int l,r;
    int maxi, lazy;
    
    node(){}
    node(int il, int ir)
    {
        l = il; r = ir;
        maxi = lazy = 0;
    }
    
    inline bool equal(int il, int ir)
    {
        return l==il && r==ir;
    }
    inline int getmid()
    {
        return (l+r)>>1;
    }
};

star stars[SIZE];
llint ys[SIZE*2];
int n,w,h;
node stree[SIZE * 8];
scanl scan_line[SIZE * 2];

void stree_init(int l, int r, int pos=0)
{
    stree[pos] = node(l, r);
    if(l<r)
    {
        uint m = (l+r)>>1;
        stree_init(l, m, left(pos));
        stree_init(m+1, r, right(pos));
    }
}

void stree_add(int l, int r, int val, int pos = 0)
{
    if(stree[pos].equal(l,r))
    {
        stree[pos].maxi += val;
        stree[pos].lazy += val;
    }
    else
    {
        int m = stree[pos].getmid();
        if(stree[pos].lazy)
        {
            stree_add(stree[pos].l, m, stree[pos].lazy, left(pos));
            stree_add(m+1, stree[pos].r, stree[pos].lazy, right(pos));
            stree[pos].lazy = 0;
        }
        
        if(l > m) stree_add(l, r, val, right(pos));
        else if(r <= m) stree_add(l, r, val, left(pos));
        else
        {
            stree_add(l, m, val, left(pos));
            stree_add(m+1, r, val, right(pos));
        }
        stree[pos].maxi = max(stree[left(pos)].maxi, stree[right(pos)].maxi);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    llint a,b,c;
    while(input(n>>w>>h))
    {
        int ans = -INF;
        memset(stree, 0, sizeof(stree));
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            stars[i]=star(a,b,c);
            ys[i*2]=b;
            ys[i*2+1]=b+h-1;
        }
        sort(ys, ys+2*n);
        map<llint,llint> mp;
        for(int i=0,j=1;i<2*n;i++)
        {
            if(mp.find(ys[i])==mp.end())
            {
                mp[ys[i]]=j++;
                //print(ys[i]<<" --> "<<mp[ys[i]]);
            }
        }
        for(int i=0;i<n;i++)
        {
            scan_line[2*i] = scanl(stars[i].x, mp[stars[i].y], mp[stars[i].y+h-1], stars[i].c);
            scan_line[2*i+1] = scanl(stars[i].x+w-1, mp[stars[i].y], mp[stars[i].y+h-1], -stars[i].c);
        }
        
        sort(scan_line, scan_line+2*n);
        stree_init(0,2*n);
        for(int i=0;i<2*n;i++)
        {
            stree_add(scan_line[i].a, scan_line[i].b, scan_line[i].c);
            ans = max(ans, stree[ROOT].maxi);
        }
        print(ans);
    }
    return 0;
}
