/*Problem: 1804		User: wizmann
 * Memory: 632K		Time: 719MS
 * Language: G++		Result: Accepted
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long sum=0;

typedef struct stree
{
	int n;
	int pos;
	stree* left;
	stree* right;
	
	stree(int m)
	{
		n=m;
		pos=1;
		left=NULL;
		right=NULL;
	}
	
	~stree()
	{
		delete this->left;
		delete this->right;
	}
}stree;

void insert(stree *root,int num)
{
	if(num>=root->n)
	{
		(root->pos)++;
		if(root->right) insert(root->right,num);
		else root->right=new stree(num);
	}
	else
	{
		sum+=(root->pos);
		if(root->left) insert(root->left,num);
		else root->left=new stree(num);
	}
}

int main()
{
	int all;
	scanf("%d",&all);
	for(int i=1;i<=all;i++)
	{
		sum=0;
		int n;
		scanf("%d",&n);
		int input;
		scanf("%d",&input);
		stree *root=new stree(input);
		while(--n)
		{
			scanf("%d",&input);
			insert(root,input);
		}
		
		printf("Scenario #%d:\n",i);
		printf("%lld\n\n",sum);
		
		root->~stree();
	}
	return 0;
}
