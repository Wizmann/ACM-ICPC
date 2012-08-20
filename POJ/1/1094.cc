#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define N 30

vector<int> g[N];
stack<int> st;
queue<int> q;
int head[N];
int temp[N];
int n;

void print()
{
	for(int i=0;i<n;i++) printf("%d ",temp[i]);
	printf("\n");
}

int judge(int ask)
{
	//如果能找到全部的顺序，返回1
	//如果找到矛盾，返回-1
	//其它返回0，继续查找
	int res=1;
	//printf("ASK:%d\n",ask);
	while(!q.empty()) q.pop();
	while((int)q.size()<n)
	{
		//print();
		while(!st.empty()) st.pop();
		for(int i=0;i<n;i++)
		{
			if(temp[i]==0) st.push(i);
		}		
		//printf("%d\n",st.size());
		if(st.size()>1) res=0;//虾米都没有找到。。。
		else if(st.size()==0) return -1;//成环咯～
		
		while(!st.empty())
		{
			int pos=st.top();
			temp[pos]=-1;
			st.pop();
			q.push(pos);
			for(int i=0;i<(int)g[pos].size();i++)
			{
				--temp[g[pos][i]];
			}
		}
	}
	if(res==0) return 0;
	printf("Sorted sequence determined after %d relations: ",ask);
	while(!q.empty())
	{
		printf("%c",'A'+q.front());
		q.pop();
	}
	printf(".\n");
	return 1;
}	

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int ask,res;
	char cmd[N];
	while(scanf("%d%d",&n,&ask)!=EOF)
	{
		//printf("%d %d\n",n,ask);
		if(n==0&&ask==0) break;
		for(int i=0;i<N;i++) g[i].clear();
		int flag=1;
		memset(head,0,sizeof(head));
		for(int i=1;i<=ask;i++)
		{
			scanf("%s",cmd);
			//puts(cmd);
			if(flag)
			{
				g[*cmd-'A'].pb(*(cmd+2)-'A');
				head[*(cmd+2)-'A']++;
				memcpy(temp,head,sizeof(temp));
				res=judge(i);
				if(res==1) flag=0;
				else if(res==-1)
				{
					printf("Inconsistency found after %d relations.\n",i);
					flag=0;
				}
			}
		}
		if(flag) printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}
			
			
