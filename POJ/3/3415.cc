//Result:wizmann	3415	Accepted	7884K	3094MS	C++	3675B

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

#define SIZE 200005

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



int main()
{
	//Sorry for wasting your time;
	freopen("input.txt","r",stdin);
	int szA,szB;
	char stringA[SIZE],stringB[SIZE];
	char team[SIZE];
	int a[SIZE],b[SIZE];
	while(input(kcount) && kcount)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(height,0,sizeof(height));
		memset(team,0,sizeof(team));
		memset(memo,0,sizeof(memo));
		scanf("%s%s",stringA,stringB);
		szA=strlen(stringA);
		szB=strlen(stringB);
		n=pad=szA+szB+2;
		int ind=0;
		for(int i=0;stringA[i];i++) memo[ind++]=stringA[i];
		memo[ind++]=1;
		for(int i=0;stringB[i];i++) memo[ind++]=stringB[i];
		memo[ind++]=0;
		creatSuffixArray();
		creatHeight();
		
		for(int i=2;i<=ind;i++)
		{
			team[i]=(sarray[i]<szA?1:0);
			height[i]-=kcount-1;
			if(height[i]<0) height[i]=0;
		}
		height[ind]=0;
		a[0]=-1;
		long long ans=0;
		for(int t=0;t<=1;t++)
		{
			for(long long c=0,ss=0,i=2;i<=n;i++)
			{
				if(team[i]!=t) ans+=ss;
				c++;
				a[c]=height[i+1];
				b[c]=team[i]==t;
				ss+=(long long)a[c]*b[c];
				while(a[c-1]>=a[c])
				{
					ss-=(long long)(a[c-1]-a[c])*b[c-1];
					a[c-1]=a[c];
					b[c-1]+=b[c];
					c--;
				}
			}
		}
		print(ans);
    }
	return 0;
}
