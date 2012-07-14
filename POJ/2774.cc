//Result:wizmann	2774	Accepted	5516K	1782MS	G++	2332B	2012-07-15 00:47:38
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define N (SIZE<<1)+5

char join[N],loc[N];
int sa[N],rank[N],height[N];
int len;

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

void makeSuffixArray()
{
	for(int i=0;i<len;i++) sa[i]=i;
	qsort(sa,len,sizeof(int),cmpSuffix);
	for(int i=0,j=0;i<len;i++)
	{
		if(i>0 and join[sa[i]]!=join[sa[i-1]]) j++;
		rank[sa[i]]=j;
	}

	int tmp[N],nextRank[N],mark[N];
	memset(mark,0,sizeof(mark));
	for(int spow=1;spow<len;spow<<=1)
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
	}
}

void makeHeight()
{
	int k=0;
	for(int i=0,j;i<len;i++)
	{
		if(rank[i]==0) height[rank[i]]=k=0;
		else
		{
			if(k>0) k--;
			j=sa[rank[i]-1];
			while(join[i+k]==join[j+k])
			{
				//print(i<<' '<<j);
				k++;
			}
			height[rank[i]]=k;
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	char *p=join;
	int sz;
	scanf("%s",p);
	sz=strlen(p);
	for(int i=0;i<sz;i++) loc[i]=1;
	p+=sz;
	*(p++)='#';
	scanf("%s",p);
	sz=strlen(p);
	p+=sz;
	*(p++)='$';
	//print(join);
	len=strlen(join);
	makeSuffixArray();
	makeHeight();
	
	//for(int i=0;i<len;i++)
	//{
	//	puts(&join[sa[i]]);
	//}
	int ans=-1;
	for(int i=1;i<len;i++)
	{
		if(loc[sa[i]]^loc[sa[i-1]])
		{
			ans=max(ans,height[i]);
		}
	}
	print(ans);
	return 0;
}
