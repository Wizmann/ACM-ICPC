//Result: 1295	Accepted	2625MS	2568K	G++	 2808B	2012-02-20 20:28:15	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

#define SIZE 100001

//用一个SET保存每一个节点的ID和PID，用来排序
//然后用两个HASH，id->add ,id->pid
//再用一个SET判断“地址是否存在”

//两个SET时间就已经很卡B了。。。
//题目居然卡了输入。。。strcmp很慢很慢。。。
//总的来说就是这个样子。。。

typedef long long llint;

struct node
{
    int id;
    int pid;
    
    node (int i_id,int i_pid)
    {
        id=i_id;
        pid=i_pid;
    }
    
    friend bool operator < (const node& a,const node& b)
    {
        if(a.pid!=b.pid) return a.pid<b.pid;
        else return a.id>b.id;
    }
};

int idpid[SIZE];
llint idadd[SIZE];

set<node> maxPid;
set<llint> memory;
int n;

inline void throwError()
{
    puts("ERROR!");
}

void create(int id,int pid,llint add)
{
    if(idpid[id]!=-1) throwError();
    else if(memory.find(add)!=memory.end()) throwError();
    else
    {
        idadd[id]=add;
        idpid[id]=pid;
        maxPid.insert(node(id,pid));
        memory.insert(add);
    }
}

void get()
{
    if(maxPid.empty()) throwError();
    else
    {
        set<node>::iterator iter=maxPid.end();
        iter--;
        
        printf("%d %d 0x%08llX\n",iter->id,iter->pid,idadd[iter->id]);
    }
}

void kill(int id)
{
    if(idpid[id]==-1) throwError();
    else
    {
        int pid=idpid[id];
        set<node>::iterator iter=maxPid.find(node(id,pid));
        //if(iter==maxPid.end()) print("ERROR:Unknown");
        
        maxPid.erase(iter);
        memory.erase(idadd[id]);
        idpid[id]=-1;
        idadd[id]=-1;
    }
}

void change(int id,int pid)
{
    if(idpid[id]==-1)
    {
        throwError();
    }
    else
    {
        llint add=idadd[id];
        kill(id);
        create(id,pid,add);
    }
}


int main()
{
	freopen("input.txt","r",stdin);
    int T,start,query;
    int a,b;llint c;
    char cmd[16];
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        printf("Case %d:\n",cas++);
        /*
        int idpid[SIZE];
        llint idadd[SIZE];

        set<node> maxPid;
        set<llint> memory;
        */
        memset(idadd,-1,sizeof(idadd));
        memset(idpid,-1,sizeof(idpid));
        maxPid.clear();
        memory.clear();
        
        
        scanf("%d%d",&n,&start);
        for(int i=0;i<start;i++)
        {
            scanf("%d%d%llX",&a,&b,&c);
            create(a,b,c);
        }
        
        scanf("%d",&query);
        for(int i=0;i<query;i++)
        {
            scanf("%s",cmd);
            if(*cmd=='C')
            {
				if(*(cmd+1)=='r')
				{
					scanf("%d%d%llX",&a,&b,&c);
					create(a,b,c);
				}
				else
				{
					scanf("%d%d",&a,&b);
					change(a,b);
				}
            }
            else if(*cmd=='G') get();
            else if(*cmd=='K')
            {
                scanf("%d",&a);
                kill(a);
            }
        }
    }
    return 0;
}
