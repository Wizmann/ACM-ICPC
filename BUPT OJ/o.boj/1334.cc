#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef struct node
{
	int left,right;
	
	void setnode()
	{
		scanf("%d%d",&left,&right);
	}
}node;

node a[25010];

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a;
	node *tb=(node*)b;
	
	return ta->left-tb->left;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++) a[i].setnode();
	
	qsort(a,n,sizeof(node),cmp);
	int i=0;
	int cur=a[0].left;
	int ans=0;
	while(cur<=t&&i<n)
	{
		int temp=cur;
		if(a[i].left>temp)
		{
			ans=-1;
			break;
		}
		while(a[i].left<=cur&&i<n)
		{
			if(a[i].right>temp) temp=a[i].right;
			i++;
		}
		ans++;
		cur=temp+1;
	}
	if(cur-1<t) ans=-1;
	if(a[0].left>1) ans=-1;
	printf("%d\n",ans);
	return 0;
}
