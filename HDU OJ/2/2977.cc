//Result:2012-08-17 20:21:59	Accepted	2977	62MS	1204K	3417 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 2000000
#define RESULT 5000
#define INF 1<<29

struct node
{
    int status;
    int step,score;
    node(){}
    node(int is,int istep,int iscore)
    {
        status=is;
        step=istep;
        score=iscore;
    }
};

const int mx[]={0,1,-1,0};
const int my[]={1,0,0,-1};
int sc[5]={0,1,10,100,1000};
bitset<SIZE> visit;
set<int> ans;
int less_step[RESULT],result[RESULT];
int g[4][4];

void makeG(int val)
{
    for(int i=2;i>=0;i--)
    {
        for(int j=2;j>=0;j--)
        {
            g[i][j]=val%5;
            val/=5;
        }
    }
}

int makeHash()
{
    int res=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            res=res*5+g[i][j];
        }
    }
    return res;
}

bool inMap(int y,int x)
{
    if(y>=0 && y<3 && x>=0 && x<3) return true;
    else return false;
}

int getVier(int y,int x)
{
    int res=0;
    for(int i=0;i<4;i++)
    {
        int ny=y+my[i];
        int nx=x+mx[i];
        if(inMap(ny,nx))
        {
            res|=1<<g[ny][nx];
        }
    }
    return res;
}


int getScore(int y,int x,int color)
{
    if(color==1)
    {
        return sc[1]-sc[g[y][x]];
    }
    else
    {
        int vier=getVier(y,x);
        if((color==2 && (vier&2)==2) ||
           (color==3 && (vier&6)==6) ||
           (color==4 && (vier&14)==14))
        {
            return sc[color]-sc[g[y][x]];
        }
        else return -INF;
    }
}

void make_all_hash()
{
    int res1,res2,res3,res4,res5,res6,res7,res8;
    res1=res2=res3=res4=res5=res6=res7=res8=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            res1=res1*5+g[i][j];
            res2=res2*5+g[j][i];
            res3=res3*5+g[2-i][j];
            res4=res4*5+g[j][2-i];
            res5=res5*5+g[i][2-j];
            res6=res6*5+g[2-j][i];
            res7=res7*5+g[2-i][2-j];
            res8=res8*5+g[2-j][2-i];
        }
    }
    visit[res1]=visit[res2]=visit[res3]=visit[res4]=visit[res5]=visit[res6]=visit[res7]=visit[res8]=1;
}

void bfs()
{
    queue<node> q;
    q.push(node(0,0,0));
    while(!q.empty())
    {
        node now=q.front();
        q.pop();
        int status=now.status;
        int step=now.step;
        int score=now.score;
        
        
        less_step[score]=min(less_step[score],step);
        
        
        if(visit[status]) continue;

        ans.insert(score);
        

        makeG(status);
        make_all_hash();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=1;k<=4;k++)
                {
                    int add=getScore(i,j,k);
                    if(add!=-INF)
                    {
                        int tmp=g[i][j];
                        g[i][j]=k;
                        int thash=makeHash();
                        if(!visit[thash])
                        {
                            q.push(node(thash,step+1,score+add));
                        }
                        g[i][j]=tmp;
                    }
                    else break;
                }
            }
        }
    }
}

int main()
{
    int ind=0,w;
    memset(less_step,0x3f,sizeof(less_step));
    bfs();
    int cas=1;
    for(set<int>::iterator iter=ans.begin();iter!=ans.end();iter++)
    {
        result[ind++]=*iter;
    }
    while(scanf("%d",&sc[1])!=EOF && sc[1]!=0)
    {
        printf("Case %d: ",cas++);
        int res=INF;
        for(int i=2;i<5;i++)
        {
            scanf("%d",&sc[i]);
        }
        scanf("%d",&w);
        for(int i=0;i<ind;i++)
        {
            int sum=0;
            int v=result[i];
            for(int j=1;j<=4;j++)
            {
                sum+=sc[j]*(v%10);
                v/=10;
            }
            
            if(sum>=w)
            {
                res=min(res,less_step[result[i]]);
            }
        }
        if(res>=INF) puts("Impossible");
        else printf("%d\n",res);
    }        
    return 0;
}
