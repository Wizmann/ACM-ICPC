//Result:wizmann    1085    Accepted    1268K    391MS    C++    1955B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define LINE 18
#define TRI 9
#define SIZE 0x3FFFF+1//状态数:18位，每一位代表一条边
#define INF 1<<25
#define MIN -INF

int line[LINE][2]=
{
    {1,2},{1,3},{2,3},
    {2,4},{2,5},{3,5},
    {3,6},{4,5},{5,6},
    {4,7},{4,8},{5,8},
    {5,9},{6,9},{6,10},
    {7,8},{8,9},{9,10}
};//18条边，每边两个点

int tri[TRI][3]={//9个三角形，三条边的编号
    {0x01,0x02,0x04},//LINE: 0,1,2
    {0x04,0x10,0x20},//LINE: 2,4,5
    {0x08,0x10,0x80},//LINE: 3,4,7
    {0x20,0x40,0x100},//etc...
    {0x200,0x400,0x8000},
    {0x80,0x400,0x800},
    {0x800,0x1000,0x10000},
    {0x100,0x1000,0x2000},
    {0x2000,0x4000,0x20000}
};
int dp[SIZE];


//寻找当前状况下，是否可以构成三角形
int calTri(int pos,int state)
{
    int flag;
    int t,res=0;
    for(int i=0;i<TRI;i++)
    {
        flag=0;t=INF;
        for(int j=0;j<3;j++)
        {
            if( (1<<pos) & tri[i][j]) t=j;//
            else if( state & tri[i][j]) flag++;//已存在的边数
        }
        if(t!=INF && flag==2) res++;
    }    
    return res;
}

int dfs(int state)
{
    if(dp[state]!=MIN) return dp[state];//记忆化搜索
    int i,t,ans=MIN;
    for(i=0;i<LINE;i++)
    {
        if(!(state&(1<<i)))//尝试每一条可能的边
        {
            t=calTri(i,state);
            if(!t) t-=dfs(state|(1<<i)); //如果没有三角形生成，交换选手  
            else t+=dfs(state|(1<<i));    
            ans=max(t,ans);
        }
    }
    dp[state]=ans;
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int T,cas=1,n;
    input(T);
    int x,y;
    
    fill(dp,dp+SIZE,MIN);
    dp[0x3FFFF]=0;//所有边填满后，结果不会再有变化

    while(T--)
    {
        printf("Game %d: ",cas++);
        input(n);
        int cnt=0,t;
        int player=1,state=0;
        for(int i=0;i<n;i++)
        {
            input(x>>y);        
            for(int j=0;j<LINE;j++)
            {
                if(x==line[j][0]&&y==line[j][1])//找出与输入边匹配的边
                {
                    t=calTri(j,state);
                    state|=(1<<j);                
                    break;        
                }
            }
            if(t) cnt+=player*t;
            else player*=-1;  
        }
        cnt+=player*dfs(state);
        if(cnt>0) print("A wins.");
        else print("B wins.");
    }    
    return 0;
}
