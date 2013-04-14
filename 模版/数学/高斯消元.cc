//Result:wizmann	1681	Accepted	1828K	16MS	C++	3009B
/*
 * Problem
 * 点灯问题：
 * 给你一个n*n个棋盘格，按下一盏灯的时候，它自己和其临近的四盏灯也会改变状态。
 * 给你一个初始状态，求把灯全部点亮需要多少操作。
 * 
 * Sample Input
 * 2
 * 3
 * yyy
 * yyy
 * yyy
 * 5
 * wwwww
 * wwwww
 * wwwww
 * wwwww
 * wwwww
 * 
 * Sample Output
 * 0
 * 15
 * 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int N = 16 + 5;
const int SIZE = N*N +5;

const int mx[]={0,1,0,-1,0};
const int my[]={-1,0,1,0,0};

int mat[SIZE][SIZE];
int tmat[SIZE][SIZE];
int ans[SIZE],x[SIZE];
int n,sz,ptr;

inline int getnr(int y,int x)
{
    if(y>=0 && y<n && x>=0 && x<n) return y*n+x;
    else return -1;
}

int dfs(int v)
{
    if(v==sz)
    {
        int temp=0;
        for(int i=0;i<sz;i++) x[i]=ans[i];
        memcpy(tmat,mat,sizeof(mat));
        for(int i=ptr-1;i>=0;i--)
        {
            for(int j=i+1;j<sz;j++)
            {
                tmat[i][sz]^=(x[j]&tmat[i][j]);
            }
            x[i]=tmat[i][sz];
        }
        for(int i=0;i<sz;i++)
        {
            if(x[i]) temp++;
        }
        return temp;
    }
    ans[v]=0;
    int res=dfs(v+1);
    ans[v]=1;
    res=min(res,dfs(v+1));
    return res;
}

int gauss()
{
    for(int row=0,col=0;row<sz && col<sz;col++)
    {
        int zptr=-1;
        for(int i=row;i<sz;i++)
        {
            if(mat[i][col])
            {
                zptr=i;
                break;
            }
        }
        if(zptr==-1) continue;
        for(int i=0;i<=sz;i++)
        {
            swap(mat[row][i],mat[zptr][i]);
        }
        for(int i=0;i<sz;i++) if(i!=row)
        {
            if(!mat[i][col]) continue;
            for(int j=0;j<=sz;j++)
            {
                mat[i][j]^=mat[row][j];
            }
        }
        row++;
        ptr=row;
    }
    if(ptr==sz)
    {
        int ans=0;
        for(int i=0;i<sz;i++)
        {
            if(mat[i][sz]) ans++;
        }
        return ans;//唯一解
    }
    else
    {
        for(int i=ptr;i<sz;i++)
        {
            if(mat[i][sz]!=0) return -1;
        }//无解
        return dfs(ptr);//有自由变元
    }
}

int main()
{
    int T;
    input(T);
    char light[N];
    while(T--)
    {
        memset(mat,0,sizeof(mat));
        memset(ans,0,sizeof(ans));
        input(n);
        sz=n*n;
        for(int i=0;i<n;i++)
        {
            scanf("%s",light);
            for(int j=0;light[j];j++)
            {
                if(light[j]=='w')
                {
                    mat[getnr(i,j)][sz]=1;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int now = getnr(i,j);
                for(int k=0;k<5;k++)
                {
                    int x=j+mx[k],y=i+my[k];
                    int pos = getnr(y,x);
                    if(pos>=0)  mat[now][pos]=1;
                }
            }
        }

        int res = gauss();
        if(res==-1) print("inf");
        else print(res);
    }
    return 0;
}
