//Result:wizmann	1226	Accepted	1000K	32MS	G++	3602B	2012-07-14 15:50:04
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
#include <deque>

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

#define SIZE 10240

int n,len;
char join[SIZE];
int sa[SIZE],rank[SIZE],mark[SIZE],height[SIZE];
int loc[SIZE];


int cmpSuffix(const void *a,const void *b)
{
	int ta=*(int*)a,tb=*(int*)b;
	return join[ta]-join[tb];
}

bool cmp(int a,int b,int spow)
{
	if(rank[a]!=rank[b]) return 1;
	else
	{
		if(rank[a+spow]!=rank[b+spow]) return 1;
		else return 0;
	}
}

void makeSuffixArray()//2倍增算法
{
	for(int i=0;i<len;i++) sa[i]=i;
	qsort(sa,len,sizeof(int),cmpSuffix);
	
	for(int i=0,j=0;i<len;i++)
	{
		if(i>0 && join[sa[i]]!=join[sa[i-1]])
		{
			j++;
		}
		rank[sa[i]]=j;
	}//初步排序
	
	
	int tmp[SIZE];
	int nextRank[SIZE];
	for(int spow=1;spow<len;spow<<=1)//2倍增算法
	{
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<len;i++)
		{
			if(sa[i]+spow<len) tmp[rank[sa[i]+spow]]++;
			else tmp[rank[sa[i]]]++;
		}
		for(int i=1;i<len;i++) tmp[i]+=tmp[i-1];
		for(int i=len-1;i>=0;i--)
		{
			if(sa[i]+spow<len) mark[--tmp[rank[sa[i]+spow]]]=sa[i];
			else mark[--tmp[rank[sa[i]]]]=sa[i];
		}
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<len;i++) tmp[rank[mark[i]]]++;
		for(int i=1;i<len;i++) tmp[i]+=tmp[i-1];
		for(int i=len-1;i>=0;i--) sa[--tmp[rank[mark[i]]]]=mark[i];
		for(int i=0,j=0;i<len;i++)
		{
			if(i>0&&cmp(sa[i],sa[i-1],spow)!=0) j++;
			nextRank[sa[i]]=j;
		}
		memcpy(rank,nextRank,sizeof(rank));
		//更新排名，要求严格的字典序
	}
}

void creatHeight()
{
	int k=0;
	for(int i=0,j=0;i<len;i++)
	{
		if(rank[i]==0) height[rank[i]]=k=0;
		else
		{
			if(k>0) k--;
			j=sa[rank[i]-1];
			while(join[i+k]==join[j+k]) k++;
			height[rank[i]]=k;
		}
	}
}

bool check(int x)
{
	int res=0;
	bitset<SIZE> visit;
	for(int i=0;i<len;i++)
	{
		if(height[i]<x)
		{
			res=0;
			visit.reset();
		}
		else
		{
			if(!visit[loc[sa[i]]])
			{
				res++;
				visit[loc[sa[i]]]=1;
			}
			if(!visit[loc[sa[i-1]]])
			{
				res++;
				visit[loc[sa[i-1]]]=1;
			}
			if(res==n) return true;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	char tmp[SIZE];
	while(T--)
	{
		memset(join,0,sizeof(join));
		memset(sa,0,sizeof(sa));
		memset(rank,0,sizeof(rank));
		memset(mark,0,sizeof(mark));
		memset(loc,0,sizeof(loc));
		memset(height,0,sizeof(height));
		int sz;
		input(n);
		char sp='z'+1;//分割符
		int p=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",tmp);
			sz=strlen(tmp);
			for(int j=0;tmp[j];j++)
			{
				join[p]=tmp[j];
				loc[p]=i;
				p++;
			}
			join[p]=sp;loc[p]=i;
			p++;sp++;
			for(int j=sz-1;j>=0;j--)
			{
				join[p]=tmp[j];
				loc[p]=i;
				p++;
			}
			join[p]=sp;loc[p]=i;
			p++;sp++;
		}
		len=p;
		makeSuffixArray();
		creatHeight();
		/*
		for(int i=0;i<len;i++)
		{
			puts(&join[sa[i]]);
		}
		* */
		int left=0,right=len;
		while(left<=right)
		{
			int mid=(left+right)>>1;
			if(check(mid))
			{
				left=mid+1;
			}
			else right=mid-1;
		}
		print(left-1);		
	}
	return 0;
}
		
		
		
			
		
		
