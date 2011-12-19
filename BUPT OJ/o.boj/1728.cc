#include <cstdio>
#include <cstring>
#include <cstdlib>

int tree[210];
char pos[210];
int time=1;

inline void init(int n)
{
	for(int i=1;i<=n;i++) tree[i]=i;
}

void setpos(int n)
{
	if(tree[n]!=n)
	{
		pos[n]=1;
		setpos(tree[n]);
	}
	else
	{
		pos[n]=1;
		return;
	}
}

int search(int n)
{
	while(tree[n]!=n)
	{
		if(pos[n]) return n;
		else n=tree[n];
	}
	return tree[n];
}
	

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,ask;
		scanf("%d",&n);
		memset(tree,0,sizeof(tree));
		init(n);
		int p,s;
		while(--n)
		{
			scanf("%d%d",&p,&s);
			tree[s]=p;
			
		}
		scanf("%d",&ask);
		printf("Case #%d:\n",time++);
		while(ask--)
		{
			memset(pos,0,sizeof(pos));
			scanf("%d%d",&p,&s);
			setpos(p);
			printf("%d\n",search(s));
		}
	}
	return 0;
}
			
