#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int NODE = 200 + 19;
const int EDGE = NODE * NODE;
const int INF  = 0x3f3f3f3f;

struct node
{
    int st, end, flow, next;
    node(){}
    node(int ist, int iend, int iflow, int inext):
            st(ist), end(iend), flow(iflow), next(inext) {}
};

int n;
node edge[EDGE];
int head[NODE];
int ind;
int source,sink;
vector<int> nums;
vector<int> cnc[NODE];
char visit[NODE];

void addEdge(int s,int e,int f)
{
    edge[ind]=node(s,e,f,head[s]);
    head[s] = ind++;
    
    edge[ind]=node(e,s,0,head[e]);
    head[e] = ind++;
}

namespace dinic
{
    int level[NODE],curhead[NODE],Que[NODE];
    int estack[4*NODE+4*EDGE],estop;
    
    int BFS()
    {
        memset(level,-1,sizeof(level));
        Que[0]=source;
        level[source]=0;
        for(int fr=0,tail=1;fr!=tail;fr=(fr+1)%NODE)
        {
            int cur=Que[fr];
            for(int e=head[cur];e!=-1;e=edge[e].next)
            {
                int next=edge[e].end;
                if(edge[e].flow && level[next] == -1)
                {
                    Que[tail]=next;
                    level[next]=level[cur]+1;
                    tail=(tail+1)%NODE;
                }
            }
        }
        return level[sink]!=-1;
    }
    
    int DFS()
    {
        int indptr,minf,e;
        int res=0;
        int cur=source;                                                   
        estop=0;
        memcpy(curhead,head,sizeof(head));  
        while(estop>=0)
        {            
            if(cur==sink)
            {                                      
                minf=INF;
                for(int i=estop-1;i>=0;i--)
                {
                    e=estack[i];
                    if(edge[e].flow<=minf)
                    {
                        minf=edge[e].flow;
                        indptr=i;
                    }
                }
                res+=minf;                                   

                for(int i=estop-1;i>=0;i--)
                {               
                    e=estack[i];
                    edge[e].flow-=minf;
                    edge[e^1].flow+=minf;
                }
                estop=indptr;                                    
                cur=edge[estack[estop]].st;          
            }
            for(e=curhead[cur];e!=-1;e=edge[e].next)
            {  
                curhead[cur]=e;
                int next=edge[e].end;
                if(edge[e].flow && level[next]==level[cur]+1)
                {
                    estack[estop++]=e;
                    cur=next;
                    break;
                }
            }
            if(e==-1)
            {                                           
                estop--;
                level[cur]=-2;                                    
                cur=edge[estack[estop]].st;               
            }
        }
        return res;
    }
}

void init()
{
    ind=0;
    memset(head,-1,sizeof(head));
    memset(visit, 0, sizeof(visit));
}

void dfs(int p, vector<int>& res) {
    res.push_back(p);
    visit[p] = 1;
    for (auto& u: cnc[p]) {
        if (visit[u]) {
            continue;
        }
        dfs(u, res);
    }
}
        
void show_res() {
    for (int i = 0; i < EDGE; i++) {
        if (edge[i].flow == 0) {
            int a = edge[i].st;
            int b = edge[i].end;
            
            if (a == source || b == source || a == sink || b == sink) {
                continue;
            }
            
            if (nums[a - 1] % 2 == 1 && nums[b - 1] % 2 == 0) {
                cnc[a].push_back(b);
                cnc[b].push_back(a);
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d -> ", i);
        for (auto& item: cnc[i]) {
            printf("%d ", item);
        }
        puts("");
    }
    puts("---");
    */
    vector<vector<int> > res;
    for (int i = 1; i <= n; i++) {
        if (visit[i]) {
            continue;
        }
        vector<int> tmp;
        dfs(i, tmp);
        res.push_back(tmp);
    }
    print(res.size());
    for (const auto& vec: res) {
        printf("%d", (int)vec.size());
        for (const auto& i: vec) {
            printf(" %d", i);
        }
        puts("");
    }
}

bool isPrime(int u) {
    if (u % 2 == 0) {
        return false;
    }
    int v = sqrt(u) + 1;
    for (int i = 3; i <= v; i += 2) {
        if (u % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("E.txt", "r", stdin);
    int x;
    input(n);
    init();
    
    source = 0;
    sink = n + 1;
    
    for (int i = 1; i <= n; i++) {
        input(x);
        nums.push_back(x);
    }
    
    for (int i = 1; i <= n; i++) {
        if (nums[i - 1] % 2 == 0) {
            continue;
        }
        for (int j = 1; j <= n; j++) {
            if (nums[j - 1] % 2 != 0) {
                continue;
            }
            if (isPrime(nums[i - 1] + nums[j - 1])) {
                addEdge(i, j, 1);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int u = nums[i - 1];
        if (u % 2 == 1) {
            addEdge(source, i, 2);
        } else {
            addEdge(i, sink, 2);
        }
    }

    int res = 0;
    while(dinic::BFS()) {
        res+=dinic::DFS();
    }
    
    if (res != n) {
        puts("Impossible");
    } else {
        show_res();
    }
    
    return 0;
}


