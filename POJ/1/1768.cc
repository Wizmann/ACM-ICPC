//Result:wizmann    1768    Accepted    4856K    188MS    G++    4299B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define CMD 16
#define N 32

struct command
{
    string name;
    int opt1,opt2;
    
    command()
    {
        name="UNKNOWN";
        opt1=opt2=0;
    }
    
    void setCmd(string i_name,int i_opt1=0,int i_opt2=0)
    {
        name=i_name;
        opt1=i_opt1;opt2=i_opt2;
    }
};

struct node
{
    long long data;
    int runpos;
    int step;
    
    node(long long i_d,int i_r,int i_s)
    {
        data=i_d;runpos=i_r;step=i_s;
    }
};
    
int n;
int g[N][N];
command cmdLine[CMD];
int VIPoint[N];
bitset<N> visit;
int inv,ans;
int hashSet[(1<<CMD)][CMD];
queue<node> q;

void pb(int a,int b)
{
    g[a][0]++;
    g[a][g[a][0]]=b;
}

void addToVIP(int p)
{
    VIPoint[0]++;
    VIPoint[VIPoint[0]]=p;
}

void dfs(int pos)
{
    if(!visit[pos])
    {
        inv++;
        visit[pos]=1;
        for(int i=1;i<=g[pos][0];i++)
        {
            if(!visit[g[pos][i]]) dfs(g[pos][i]);
        }
    }
}

long long memToInt(char *data)
{
    long long res=0;
    for(int i=0;i<N;i++)
    {
        if(data[i]) res+=(1LL<<i);
    }
    return res;
}

void intToMem(long long mem,char *data)
{
    int i=0;
    while(mem>0)
    {
        data[i]=(mem&1);
        i++;
        mem>>=1;
    }
}

int MemZip(long long memory)
{
    int res=0;
    for(int i=0;i<N;i++)
    {
        if(visit[i])
        {
            res<<=1;
            res+=memory&1;
        }
        memory>>=1;
    }
    return res;
}
        

int doCommand(const node& now)
{
    long long memory=now.data;
    int runpos=now.runpos;
    int step=now.step;
    
    int zipMemory=MemZip(memory);
    
    if(hashSet[zipMemory][runpos]==-1 || hashSet[zipMemory][runpos]>step+1)
    {
        hashSet[zipMemory][runpos]=step+1;
    }
    else return 0;
    
    char data[N]={0};
    intToMem(memory,data);
    
    int a=cmdLine[runpos].opt1;
    int b=cmdLine[runpos].opt2;
    string name=cmdLine[runpos].name;
    /*
    for(int j=0;j<N;j++) printf("%d",data[j]);
    print("");
    
    */
    //print(step<<':'<<name<<" "<<a<<' '<<b);
    
    step++;
    runpos++;
    if(name=="AND") data[a]&=data[b];
    else if(name=="OR") data[a]|=data[b];
    else if(name=="XOR") data[a]^=data[b];
    else if(name=="NOT") data[a]=(!data[a]);
    else if(name=="MOV") data[a]=data[b];
    else if(name=="SET") data[a]=b;
    else if(name=="JMP") runpos=a;
    else if(name=="JZ")
    {
        if(!data[b]) runpos=a;
    }
    else if(name=="RANDOM")
    {
        data[a]=0;
        q.push(node(memToInt(data),runpos,step));
        data[a]=1;
    }
    else if(name=="STOP")
    {
        ans=min(ans,step);
        return 1;
    }
    /*
    for(int j=0;j<N;j++) printf("%d",data[j]);
    print("");
    print(memToInt(data)<<' '<<runpos<<' '<<step);
    */
    q.push(node(memToInt(data),runpos,step));
    return 0;
}
    
    

bool exe()
{
    bool flag=false;
    char data[N];
    for(long long i=0;i<(1LL<<inv);i++)
    {
        //print("__________");
        bitset<N> bs(i);
        memset(data,0,sizeof(data));
        for(int j=0,k=0;j<N;j++)
        {
            if(visit[j]) data[j]=bs[k++];
        }
        //for(int j=0;j<N;j++) printf("%d",data[j]);
        //print("");
        while(!q.empty()) q.pop();
        //print(memToInt(data));
        q.push(node(memToInt(data),0,0));
        int res=0;
        while(!q.empty())
        {
            node now=q.front();
            q.pop();
            if(res=doCommand(now)) break;
        }
        if(res==1)
        {
            //print("<!---ANS---> "<<ans);
            flag=true;
        }
        //else print("FAILED!!");
    }
    return flag;
}
        
        

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ans=1<<25;
    string cmd;
    int a,b;
    input(n);
    memset(hashSet,-1,sizeof(hashSet));
    for(int i=0;i<n;i++)
    {
        input(cmd);
        if(cmd=="AND" || cmd=="OR" || cmd=="XOR" || cmd=="MOV")
        {
            input(a>>b);
            cmdLine[i].setCmd(cmd,a,b);
            pb(a,b);
        }
        else if(cmd=="SET")
        {
            input(a>>b);
            cmdLine[i].setCmd(cmd,a,b);
        }
        else if(cmd=="JZ")
        {
            input(a>>b);
            cmdLine[i].setCmd(cmd,a,b);
            addToVIP(b);
        }
        else if(cmd=="STOP")
        {
            cmdLine[i].setCmd(cmd);
        }
        else
        {
            input(a);
            cmdLine[i].setCmd(cmd,a);
        }
    }
    visit.reset();
    inv=0;
    for(int i=1;i<=VIPoint[0];i++)
    {
        //print(VIPoint[i]);
        dfs(VIPoint[i]);
    }
    //for(int i=0;i<N;i++) if(visit[i]) printf("%d ",i);
    //print("");
    if(exe()) print(ans);
    else print("HANGS");
    return 0;
}
