//Result:Wizmann	2221	Accepted	GNU C++	1.76k	0ms	1376KB	2013-04-23 20:41:26
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 128;
const int mx[] = {-1,-1,-1, 0, 0, 1, 1, 1, 2,-2, 0, 0};
const int my[] = {-1, 0, 1, 1,-1,-1, 0, 1, 0, 0, 2,-2};
const int MOVE = sizeof(mx)/sizeof(int);

int n,m;
int g[SIZE][SIZE];
int ind;
int father[SIZE*SIZE];

int find_father(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    else
    {
        return father[x] = find_father(father[x]);
    }
}

void make_union(int a, int b)
{
    father[find_father(a)]=find_father(b);
}

int main()
{
    char s[SIZE];
    while(input(n>>m))
    {
        ind = 0;
        memset(g,0,sizeof(g));
        for(int i=0;i<SIZE*SIZE;i++)
        {
            father[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;s[j];j++)
            {
                if(s[j]=='#')
                {
                    g[i][j]=(++ind);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j])
                {
                    for(int k=0;k<MOVE;k++)
                    {
                        int x=j,y=i;
                        x+=mx[k];
                        y+=my[k];
                        if(x>=0 && x<m && y>=0 && y<n && g[y][x])
                        {
                            make_union(g[i][j],g[y][x]);
                        }
                    }
                }
            }
        }
        set<int> ans;
        for(int i=1;i<=ind;i++)
        {
            ans.insert(find_father(father[i]));
        }
        print(ans.size());
    }
    return 0;
}





