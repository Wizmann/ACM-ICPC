/*
King Arthur's Knights
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 1332    Accepted Submission(s): 520
Special Judge

Problem Description
I am the bone of my sword. Steel is my body, and the fire is my blood.
- from Fate / Stay Night
You must have known the legend of King Arthur and his knights of the round table. The round table has no head, implying that everyone has equal status. Some knights are close friends with each other, so they prefer to sit next to each other.

Given the relationship of these knights, the King Arthur request you to find an arrangement such that, for every knight, his two adjacent knights are both his close friends. And you should note that because the knights are very united, everyone has at least half of the group as his close friends. More specifically speaking, if there are N knights in total, every knight has at least (N + 1) / 2 other knights as his close friends.
 
Input
The first line of each test case contains two integers N (3 <= N <= 150) and M, indicating that there are N knights and M relationships in total. Then M lines followed, each of which contains two integers ai and bi (1 <= ai, bi <= n, ai != bi), indicating that knight ai and knight bi are close friends.
 
Output
For each test case, output one line containing N integers X1, X2, ..., XN separated by spaces, which indicating an round table arrangement. Please note that XN and X1 are also considered adjacent. The answer may be not unique, and any correct answer will be OK. If there is no solution exists, just output "no solution".
 
Sample Input

3 3 
1 2 
2 3 
1 3 
4 4 
1 4 
2 4 
2 3 
1 3 

Sample Output

1 2 3 
1 4 2 3
*/

//Result:2012-08-02 21:37:32	Accepted	4337	15MS	400K	1490 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256
#define pb push_back

int n,m;
int visit[SIZE];
stack<int> st;
vector<int> g[SIZE];

bool dfs(int pos,int step=0)
{
    visit[pos]=step;
    st.push(pos);
    for(int i=0;i<(int)g[pos].size();i++)
    {
        int next=g[pos][i];
        if(visit[next]==-1)
        {
            if(dfs(next,step+1)) return true;
        }
        else if(visit[next]+n-1==step)//<-这里是n元环，可以根据需要进行修改
        {
            return true;
        }
    }
    visit[pos]=-1;
    st.pop();
    return false;
}

int main()
{
    int a,b;
    while(input(n>>m))
    {
        memset(visit,-1,sizeof(visit));
        while(!st.empty()) st.pop();
        for(int i=0;i<SIZE;i++) g[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].pb(b);
            g[b].pb(a);
        }
        if(dfs(1))
        {
            bool flag=false;
            while(!st.empty())
            {
                if(flag) printf(" ");
                else flag=true;
                printf("%d",st.top());
                st.pop();
                //There is a pe point;
            }
            puts("");
        }
        else puts("no solution");
    }
    return 0;
}
