//Result:Jan 14, 2013 5:38:36 PM	Wizmann	 E - Dividing Kingdom	 GNU C++	Accepted	 436 ms	 20800 KB
#include <iostream>  
#include <cstdio>  
#include <map>  
#include <cstring>  
#include <cmath>  
#include <vector>  
#include <algorithm>  
#include <set>  
#include <string>  
#include <queue>  

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100005
#define SON 9
#define pb(x) push_back(x)

const int ROOT=0;

inline int lson(int x){return x*2+1;}
inline int rson(int x){return x*2+2;}

struct node
{
    int l,r;
    vector<int> vec;
    node(){}
    node(int il,int ir)
    {
		l=il;r=ir;
		vec.clear();
	}
	inline bool equal(int ix){return ix==l && ix==r;}
	inline bool equal(int il,int ir){return l==il&&r==ir;}
	inline int getmid(){return (l+r)>>1;}
};

struct point
{
    int x,y;
    point(){}
    point(int ix,int iy){x=ix;y=iy;}
    bool operator < (const point n) const
    {
        return x!=n.x?x<n.x:y<n.y;
    }
};

point city[SIZE];
int n,xx[SIZE],yy[SIZE],son[SON];
node stree[SIZE*4];

double ret_x1,ret_x2,ret_y1,ret_y2;

void stree_bulid(int l,int r,int pos=ROOT)
{
    stree[pos]=node(l,r);
    for(int i=l;i<=r;i++)
    {
		stree[pos].vec.pb(city[i].y);
	}
    sort(stree[pos].vec.begin(),stree[pos].vec.end());
    if(l>=r) return;
    int mid=(l+r)>>1;
    stree_bulid(l,mid,lson(pos));
    stree_bulid(mid+1,r,rson(pos));
}

int stree_query(int l,int r,int val,int pos=ROOT)
{
    if(stree[pos].equal(l,r))
    {
		return upper_bound(stree[pos].vec.begin(),stree[pos].vec.end(),val)-stree[pos].vec.begin();
    }
	else
	{
		int mid=stree[pos].getmid();
		if(r<=mid) return stree_query(l,r,val,lson(pos));
		else if(l>mid) return stree_query(l,r,val,rson(pos));
		else return stree_query(l,mid,val,lson(pos))+stree_query(mid+1,r,val,rson(pos));
	}
}

bool slove()
{
    int x1=son[0]+son[1]+son[2]-1;
    int x2=x1+son[3]+son[4]+son[5];
    
    int y1=son[0]+son[3]+son[6]-1;
    int y2=y1+son[1]+son[4]+son[7];
    
    if(x1+1>=n || xx[x1]==xx[x1+1]) return false;
    if(x2+1>=n || xx[x2]==xx[x2+1]) return false;
    if(y1+1>=n || yy[y1]==yy[y1+1]) return false;
    if(y2+1>=n || yy[y2]==yy[y2+1]) return false;
    
    if(stree_query(0,x1,yy[y1])!=son[0]) return false;
    if(stree_query(0,x1,yy[y2])!=son[0]+son[1]) return false;
    if(stree_query(x1+1,x2,yy[y1])!=son[3]) return false;
    if(stree_query(x1+1,x2,yy[y2])!=son[3]+son[4]) return false;
    
    ret_x1=(xx[x1]+xx[x1+1])/2.0;
    ret_x2=(xx[x2]+xx[x2+1])/2.0;
    ret_y1=(yy[y1]+yy[y1+1])/2.0;
    ret_y2=(yy[y2]+yy[y2+1])/2.0;
    
    return true; 
}

int main()
{
	freopen("e.txt","r",stdin);
    while(input(n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&city[i].x,&city[i].y);
            xx[i]=city[i].x;yy[i]=city[i].y;
        }
        sort(city,city+n);
        sort(xx,xx+n);
        sort(yy,yy+n);
        stree_bulid(0,n-1);
        for(int i=0;i<9;i++) scanf("%d",&son[i]);
        bool flag=false;
        do
        {
			flag=slove();
			if(flag)
			{
				printf("%.1f %.1f\n%.1f %.1f\n",ret_x1,ret_x2,ret_y1,ret_y2);
				break;
			}
		}
		while(next_permutation(son,son+SON));
        if(!flag) puts("-1");
    }
    return 0;
}
