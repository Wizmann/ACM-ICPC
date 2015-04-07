//Result:wizmann    3261    Accepted    1516K   125MS   C++ 3081B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
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
#define mp make_pair
#define np next_permutation

#define SIZE 80000
#define N 256

int n,kcount;
int pad,spow;
int memo[SIZE];//拼接出的长字符串
int rank[SIZE];
int sarray[SIZE];//后辍数组
int mark[SIZE];
int height[SIZE];
//height 数组:定义 height[i]=suffix(sa[i-1])和 suffix(sa[i])的最长公
//共前缀,也就是排名相邻的两个后缀的最长公共前缀。


int cmpSuffix(const void *a,const void *b)
{
    int ta=*(int*)a,tb=*(int*)b;
    return memo[ta]-memo[tb];
}

int cmp(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    if(rank[x]!=rank[y]) return 1;
    else
    {
        if(rank[x+spow]!=rank[y+spow]) return 1;
        else return 0;
    }
}

void creatSuffixArray()
{
    for(int i=0;i<pad;i++) sarray[i]=i;
    qsort(sarray,pad,sizeof(int),cmpSuffix);//后辍排序
    
    for(int i=0,j=0;i<pad;i++)
    {
        if(i>0 && memo[sarray[i]]!=memo[sarray[i-1]]) j++;
        rank[sarray[i]]=j;//后辍排名
    }
    
    int tmpstr[SIZE];
    int nextRank[SIZE];
    for(spow=1;spow<pad;spow<<=1)//2倍增算法
    {
        memset(tmpstr,0,sizeof(tmpstr));
        for(int i=0;i<pad;i++)
        {
            if(sarray[i]+spow<pad) tmpstr[rank[sarray[i]+spow]]++;
            else tmpstr[rank[sarray[i]]]++;
        }
        for(int i=1;i<pad;i++) tmpstr[i]+=tmpstr[i-1];
        for(int i=pad-1;i>=0;i--)
        {
            if(sarray[i]+spow<pad) mark[--tmpstr[rank[sarray[i]+spow]]]=sarray[i];
            else mark[--tmpstr[rank[sarray[i]]]]=sarray[i];
        }
        memset(tmpstr,0,sizeof(tmpstr));
        for(int i=0;i<pad;i++) tmpstr[rank[mark[i]]]++;
        for(int i=1;i<pad;i++) tmpstr[i]+=tmpstr[i-1];
        for(int i=pad-1;i>=0;i--) sarray[--tmpstr[rank[mark[i]]]]=mark[i];
        for(int i=0,j=0;i<pad;i++)
        {
            if(i>0&&cmp(&sarray[i],&sarray[i-1])!=0) j++;
            nextRank[sarray[i]]=j;
        }
        memcpy(rank,nextRank,sizeof(rank));
        //更新排名，要求严格的字典序
    }
}

void creatHeight()
{
    int k=0;
    for(int i=0,j=0;i<pad;i++)
    {
        if(rank[i]==0) height[rank[i]]=k=0;
        else
        {
            if(k>0) k--;
            j=sarray[rank[i]-1];
            while(memo[i+k]==memo[j+k]) k++;
            height[rank[i]]=k;
        }
    }
}

int judge(int len)
{
    int sum=0;
    for(int i=1;i<pad;i++)
    {
        if(height[i]>=len)
        {
            sum++;
            if(sum==kcount-1) return 1;
        }
        else sum=0;
    }
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    input(n>>kcount);
    pad=0;
    for(int i=0;i<n;i++) input(memo[i]);
    memo[n++]=-1;
    pad=n;
    creatSuffixArray();
    creatHeight();
    
    /*
    for(int i=0;i<pad;i++)
    {
        int t=sarray[i];
        for(int j=t;j<pad;j++) printf("%d ",memo[j]);
        print("");
    }
    */
    
    int i=0,j=pad;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(judge(mid)) i=mid+1;
        else j=mid-1;
    }
    print(j);
    return 0;
}
