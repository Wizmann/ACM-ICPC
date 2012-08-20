//Result:wizmann    3317    Accepted    4864K    782MS    G++    3912B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10
#define INF 1<<25
#define DIGIT 64
#define STATUS 0xFFFFF
#define DPSIZE STATUS+5000

typedef long long llint;
typedef unsigned long long int ullint;

struct point
{
    int x,y;
    point(){}
    point(int i_x,int i_y)
    {
        x=i_x;y=i_y;
    }
    
    void setpoint(int i_x,int i_y)
    {
        x=i_x;y=i_y;
    }
    
    friend bool operator < (const point &a ,const point &b)
    {
        if(a.y!=b.y) return a.y<b.y;
        else return a.x<b.x;
    }
    
    void printPoint()
    {
        cout<<"("<<y<<","<<x<<") ";
    }
};

int n;
char g[SIZE][SIZE];
char visit[SIZE][SIZE];
point ansPnt;
int alice,bob;
int ans,ind;
int space[SIZE],dp[DPSIZE];

const int mx[]={0 , 0, 1,-1};
const int my[]={1 ,-1, 0, 0};

int search(int x,int y)
{
    int res=0;
    stack<point> st;
    st.push(point(x,y));
    visit[y][x]=1;
    while(!st.empty())
    {
        point now=st.top();
        st.pop();
        res++;
        for(int i=0;i<4;i++)
        {
            point next(now.x+mx[i],now.y+my[i]);
            if(next.x>=0 && next.x<n && next.y>=0 && next.y<n)
            {
                if(!visit[next.y][next.x]&&g[next.y][next.x]==g[y][x])
                {
                    st.push(next);
                    visit[next.y][next.x]=1;
                }
            }
        }
    }
    return res;
}
int getAns()
{
    memset(visit,0,sizeof(visit));
    alice=0;bob=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]) continue;
            
            if(g[i][j]=='0') alice=max(alice,search(j,i));
            else if(g[i][j]=='1') bob=max(bob,search(j,i));
            else print("Dot Error");
        }
    }
    return alice-bob;
}

void printBin(ullint t)
{
    while(t)
    {
        printf("%lld",t&1);
        t>>=1;
    }
    print("");
}

inline ullint EOS()//In memory of Moser, the Mr.__End_Of_Story__
{
    if(n==8) return -1;
    else return (1ULL<<(n*n))-1;
}

void printG()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) printf("%c",g[i][j]);
        print("");
    }
}

int addfill(int pre,int now,int next)
{
    next++;
    //printf("%x %x %x\n",pre,now,next);
    int res=pre|(next<<(now*2));
    //printf("%x\n",res);
    return res;
}

int dfs(int next,ullint status,int fill)
{
    if(dp[fill]!=INF) return dp[fill];
    else if(status==EOS()) return dp[fill]=getAns();
    else
    {
        int ans;
        if(next==0) ans=-INF;
        else ans=INF;
        
        for(int i=0;i<ind;i++)
        {
            int now=space[i];
            if(!(status & (1ULL<<now)))
            {
                g[now/n][now%n]=next+'0';
                int newfill=addfill(fill,i,next);
                if(next==0) ans=max(ans,dfs(next^1,status|(1ULL<<now),newfill));
                else ans=min(ans,dfs(next^1,status|(1ULL<<now),newfill));
                g[now/n][now%n]='.';
            }
        }
        return dp[fill]=ans;
    }
}

void slove(ullint status)
{
    int next;
    if(alice>bob) next=1;
    else next=0;
    
    if(next==0) ans=-INF;
    else ans=INF;
    
    for(int i=0;i<ind;i++)
    {
        int now=space[i];
        g[now/n][now%n]=next+'0';
        int fill=addfill(0,i,next);
        int t=dfs(next^1,status|(1ULL<<now),fill);
        g[now/n][now%n]='.';
        
        if(next==0)
        {
            if(t>ans)
            {
                ans=t;
                ansPnt.setpoint(now%n,now/n);
            }
            else if(t==ans) ansPnt=min(ansPnt,point(now%n,now/n));
        }
        else
        {
            if(t<ans)
            {
                ans=t;
                ansPnt.setpoint(now%n,now/n);
            }
            else if(t==ans) ansPnt=min(ansPnt,point(now%n,now/n));
        }
    }
    if(next==1) ans*=-1;
    ansPnt.printPoint();
}
        

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(input(n) && n)
    {
        memset(space,0,sizeof(space));
        fill(dp,dp+DPSIZE,INF);
        ans=-INF;
        ind=0;
        alice=bob=0;//A->0 B->1
        ansPnt.x=ansPnt.y=INF;
        ullint status=0;
        for(int i=0;i<n;i++)
        {
            input(g[i]);
            for(int j=0;g[i][j];j++)
            {
                if(g[i][j]=='0') alice++;
                else if(g[i][j]=='1') bob++;
                if(g[i][j]!='.') status|=1LL<<(i*n+j);
                else space[ind++]=(i*n+j);
            }
        }
        slove(status);
        print(ans);
    }
    return 0;
}
