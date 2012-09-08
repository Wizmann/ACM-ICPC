//Result:2012-09-06 20:09:20	Accepted	3699	0MS	308K	1473 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x


typedef long long llint;

char word[3][15];
char mp[521];
int sz,ans;
int val[8];
char visit[12],cap[12];

void dfs(int p=0)
{
	if(p==sz)
	{
		int num[3]={0,0,0};
		for(int i=0;i<3;i++)
		{
			for(int j=0;word[i][j];j++)
			{
				num[i]=num[i]*10+val[int(word[i][j]-'A')];
			}
		}
		
		if(num[0]+num[1]==num[2]) ans++;
		if(num[0]-num[1]==num[2]) ans++;
		if((llint)num[0]*num[1]==num[2]) ans++;
		if(num[1]!=0 && num[0]==(llint)num[1]*num[2]) ans++;
	}
	else
	{
		for(int i=0;i<=9;i++) if(!visit[i])
		{
			if(i==0 && cap[p]) continue;
			else 
			{
				val[p]=i;
				visit[i]=1;
				dfs(p+1);
				visit[i]=0;
			}
		}
	}
}
	

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		sz=ans=0;
		memset(mp,0,sizeof(mp));
		memset(visit,0,sizeof(visit));
		memset(cap,0,sizeof(cap));
		for(int i=0;i<3;i++) scanf("%s",word[i]);
		for(int i=0;i<3;i++)
		{
			for(int j=0;word[i][j];j++)
			{
				if(mp[int(word[i][j])]==0)
				{
					mp[int(word[i][j])]='A'+sz;
					sz++;
				}
			}
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;word[i][j];j++)
			{
				word[i][j]=mp[int(word[i][j])];
				if(j==0 && strlen(word[i])>1) cap[word[i][j]-'A']=1;
			}
		}
		dfs();
		print(ans);
	}
	return 0;
}
		
