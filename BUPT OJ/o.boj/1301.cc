#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define pb push_back
#define mp make_pair
#define pb push_back
#define elif else if

const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};
const char mv[]="urdl";

typedef struct node
{
    int x,y;
    int step;
    string mem;
    
    node()
    {
        x=y=step=0;
        mem="";
    }
    
    inline void setnode(int a,int b,int s,char c)
    {
        step=s;
        x=a;y=b;
        if(c) mem+=c;
    }
}node;

queue<node> q;
char g[20][20];
int l,w;
char visit[20][20];

void bfs()
{
    memset(visit,0,sizeof(visit));
    int ans=1<<20;
    node res;
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        //print(t.x<<' '<<t.y);
        if(t.step>=ans) continue;
        visit[t.y][t.x]=1;
        for(int i=0;i<4;i++)
        {
            int x=t.x,y=t.y;
            int move=0;
            while(g[y][x]!='#' && g[y][x]!='E' && x>=0 && x<w && y>=0 && y<l)
            {
                y+=my[i];x+=mx[i];
                move++;
            }
            if( (move==1&&g[y][x]!='E') || x<0 || x>=w || y<0 || y>=l) continue;
            elif(g[y][x]=='#' || g[y][x]=='E')
            {
                int ty=y,tx=x;
                y-=my[i];x-=mx[i];
                node temp=t;
                temp.setnode(x,y,t.step+1,mv[i]);
                if(!visit[y][x] && g[ty][tx]!='E')
                {
                    visit[y][x]=1;
                    q.push(temp);
                }
                elif(g[ty][tx]=='E')
                {
                    ans=min(ans,temp.step);
                    res=temp;
                }
            }
        }
    }
    print(ans);
    print(res.mem);
}
        
int main()
{
    int cas=1;
    while(scanf("%d%d",&l,&w)!=EOF)
    {
        if(l+w<=0) break;
        print("Case "<<cas++<<":");
        while(!q.empty()) q.pop();
        bool start=false;
        for(int i=0;i<l;i++)
        {
            input(g[i]);
            if(!start)
            {
                for(int j=0;g[i][j];j++)
                {
                    if(g[i][j]=='S')
                    {
                        start=true;
                        node t;
                        t.setnode(j,i,0,'\0');
                        q.push(t);
                    }
                }
            }
        }
        bfs();
    }
    return 0;
}
