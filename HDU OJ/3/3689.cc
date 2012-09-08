//Result:2012-09-05 21:18:49	Accepted	3689	15MS	508K	1531 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024


int to[SIZE][26];
char word[12];
int next[SIZE];
int n,q;
double pp[512];
double dp[SIZE][12];

void kmp_get_next()
{
	memset(to,0,sizeof(to));
	int len=strlen(word);
	next[0]=-1;
	for(int i=0,j=-1;i<len;i++,j++,next[i]=j)
	{
		while(j>=0 && word[i]!=word[j]) j=next[j];
	}
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<26;j++)
		{
			int nx=i;
			while(nx!=-1 && word[nx]!='a'+j) nx=next[nx];
			to[i][j]=++nx;
		}
	}
}

double slove()
{
	int len=strlen(word);
	//for(int i=0;i<len;i++) next[i]+=1;
	memset(dp,0,sizeof(dp));
	dp[0][0]=100;
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(dp[i][j]>1e-7)
			{
				double now=dp[i][j];
				dp[i+1][j+1]+=now*pp[int(word[j])];
				for(int k=0;k<26;k++) if(k+'a'!=word[j])
				{
					int nx=to[j][k];
					dp[i+1][nx]+=now*pp[int('a'+k)];
				}
			}
		}
		dp[i+1][len]+=dp[i][len];
	}
	/*
	for(int i=0;i<=q;i++)
	{
		for(int j=0;j<=len;j++)
		{
			printf("%.2lf ",dp[i][j]);
		}
		puts("");
	}
	*/
	return dp[q][len];
}


int main()
{
	freopen("input.txt","r",stdin);
	char cmd[10];
	double tmp;
	while(input(n>>q) && n+q)
	{
		memset(pp,0,sizeof(pp));
		for(int i=0;i<n;i++)
		{
			scanf("%s%lf",cmd,&tmp);
			pp[int(*cmd)]=tmp;
		}
		scanf("%s",word);
		kmp_get_next();
		printf("%.2lf%%\n",slove());
	}
	return 0;
}

