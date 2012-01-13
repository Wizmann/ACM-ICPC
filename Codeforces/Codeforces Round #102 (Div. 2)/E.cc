#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define SIZE 9

//###      ..#      .#.      #..
//.#.      ###      .#.      ###
//.#.      ..#      ###      #..

const int shape[4][4][2]={ //set the upper left grid as the centre
        {{0,1},{0,2},{1,1},{2,1}},
        {{1,0},{2,0},{1,-1},{1,-2}},
        {{1,0},{2,0},{2,-1},{2,1}},
        {{1,0},{2,0},{1,1},{1,2}}
        };
int x,y;

struct node
{
    char g[SIZE][SIZE];
    int num;
    int sx,sy;
    
    node()
    {
        sx=sy=0;
        memset(g,0,sizeof(g));
        num=0;
    }
    
    void printNode()
    {
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++) printf("%c",g[i][j]?g[i][j]:'.');
            print("");
        }
    }
};

stack<node> q;
int ans;
node ansNode;

void bfs()
{
    while(true)
    {
The_End_Where_I_Began: //Line Name
        if(q.empty()) break;
        node now=q.top();
        q.pop();
        if(now.num>ans)
        {
            ans=now.num;
            ansNode=now;
        }
        now.num++;
        char ch='A'+now.num-1;
        bool flag=true;
        for(int i=0;i<y;i++)
        {
            int in=0;
            for(int j=0;j<x;j++)
            {
                if(!now.g[i][j])
                {
                    flag=true;
                    for(int k=3;k>=0;k--)
                    {
                        flag=true;
                        
                        for(int l=0;l<4;l++)
                        {
                            int tx=j+shape[k][l][1];
                            int ty=i+shape[k][l][0];
                            if(tx<0 || tx>=x || ty<0 || ty>=y || now.g[ty][tx])
                            {
                                flag=false;
                                break;
                            }
                        }
                        
                        if(flag)
                        {
                            in++;
                            node tNode=now;
                            tNode.g[i][j]=ch;
                            for(int l=0;l<4;l++)
                            {
                                int tx=j+shape[k][l][1];
                                int ty=i+shape[k][l][0];
                                tNode.g[ty][tx]=ch;
                            }
                            tNode.sx=j+1;
                            tNode.sy=i;
                            q.push(tNode);
                        }
                    }
                    if(in>1) goto The_End_Where_I_Began;
                }
            }
           
        }
    }
}
                        

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ans=-1;
    input(y>>x);
    while(!q.empty()) q.pop();
    q.push(node());
    bfs();
    print(ans);
    ansNode.printNode();
    return 0;
}
