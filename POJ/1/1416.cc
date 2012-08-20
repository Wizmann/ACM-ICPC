//Result:wizmann	1416	Accepted	736K	0MS	G++	1317B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int sum,len;
int ans,get;
char num[120];
bool rej;

stack<int> q;
stack<int> save;

int length(int x)
{
	if(x==0) return 1;
	else
	{
		int res=0;
		while(x>0)
		{
			x/=10;res++;
		}
		return res;
	}
}

void dfs(int pos=0,int s=0)
{
	if(s>sum) return;
	if(pos==len)
	{
		if(s<=sum&&s>get)
		{
			rej=false;
			ans++;
			get=s;
			save=q;
		}
		else if(s==get) rej=true;
	}
	else
	{
		int t=0;
		for(int i=pos;i<len;i++)
		{
			t=t*10+num[i]-'0';
			if(t<=sum)
			{
				q.push(t);
				dfs(i+1,s+t);
				q.pop();
			}
			else break;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(1)
	{
		rej=false;
		memset(num,0,sizeof(num));
		ans=0;get=-1;
		while(!q.empty()) q.pop();
		while(!save.empty()) save.pop();
		scanf("%d%s",&sum,num);
		if(sum==0) break;
		len=strlen(num);
		dfs();
		if(ans==0) puts("error");
		else if(rej) puts("rejected");
		else
		{
			stack<int> temp;
			printf("%d",get);
			while(!save.empty())
			{
				int t=save.top();save.pop();
				temp.push(t);
			}
			while(!temp.empty())
			{
				printf(" %d",temp.top());
				temp.pop();
			}
			puts("");
		}
	}
	return 0;
}
			
			
		
