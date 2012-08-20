#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 30010

int up[MAX],father[MAX],down[MAX];

void init()
{
	memset(up,0,sizeof(up));
	for(int i=0;i<MAX;i++)
	{
		father[i]=i;
		down[i]=1;
	}
}

int find(int n)
{
	if(father[n]==n) return n;
	else
	{
		int f=father[n];
		father[n]=find(f);
		up[n]+=up[f];
		return father[n];
	}
}

void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b) return;
	else
	{
		father[b]=a;
		up[b]+=down[a];
		down[a]+=down[b];
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int ask,a,b;
	char cmd[3];
	init();
	scanf("%d",&ask);
	while(ask--)
	{
		scanf("%s%d",cmd,&a);
		if(*cmd=='M')
		{
			scanf("%d",&b);
			Union(a,b);
		}
		else printf("%d\n",down[find(a)]-up[a]-1);
	}
	return 0;
}
