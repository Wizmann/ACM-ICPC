//Result:Accepted    1074    765MS    628K    2017 B    G++    Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 15
#define SIZE (1<<N)
#define INF 1<<25

struct task
{
    string name;
    int need,dline;
    int pos;
    
    friend bool operator < (const task& a,const task& b)
    {
        return a.name<b.name;
    }
};

struct node
{
    int day,loss;
    
    void setnode(int i_day,int i_loss)
    {
        if(i_loss>0) loss=i_loss;
        day=i_day;
    }
    
    void clearnode()
    {
        day=loss=0;
    }
};

node dp[SIZE];
task array[N];
bitset<N> visit;
int n,ans;
stack<int> memo,ansStack;

void dfs(int father,int x)
{
    if(dp[father].loss>=ans) return;
    memo.push(x);
    
    if(father==(1<<n)-1)
    {
        if(dp[father].loss<ans)
        {
            ansStack=memo;
            ans=dp[father].loss;
        }
        memo.pop();
        return;
    }
    
    visit[x]=1;
    for(int i=0;i<n;i++) if(!visit[i])
    {
        int dpPos=father | array[i].pos;
        int day=dp[father].day+array[i].need;
        int loss=dp[father].loss;
        if(day-array[i].dline>0)
        {
            loss+=day-array[i].dline;
        }
        if(dp[dpPos].loss&&loss>=dp[dpPos].loss) continue;
        dp[dpPos].setnode(day,loss);
        dfs(dpPos,i);
    }
    memo.pop();
    visit[x]=0;
}

int main()
{
    freopen("input.txt","r",stdin);
    int T;
    input(T);
    while(T--)
    {
        ans=INF;
        memset(dp,0,sizeof(dp));
        input(n);
        for(int i=0;i<n;i++)
        {
            input(array[i].name);
            input(array[i].dline>>array[i].need);
        }
        //sort(array,array+n);
        for(int i=0;i<n;i++)
        {
            array[i].pos=1<<i;
            dp[array[i].pos].setnode(array[i].need,array[i].need-array[i].dline);
        }
        for(int i=0;i<n;i++)
        {
            while(!memo.empty()) memo.pop();
            visit.reset();
            dfs(array[i].pos,i);
        }

        print(ans);
        stack<int> rev;
        while(!ansStack.empty())
        {
            rev.push(ansStack.top());
            ansStack.pop();
        }
        while(!rev.empty())
        {
            print(array[rev.top()].name);
            rev.pop();
        }
    }
    return 0;
}
