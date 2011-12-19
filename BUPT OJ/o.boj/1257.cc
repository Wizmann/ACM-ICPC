#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct leaf
{
	int num;
	int pos;
	leaf *left;
	leaf *right;
	
	leaf(int n)
	{
		num=n;
		pos=0;
		left=NULL;
		right=NULL;
	}	
	~leaf()
	{
		delete this->left;
		delete this->right;
	}
}leaf;

int counter=1;

void insert(leaf *father,int n)
{
	if(n<father->num)
	{
		(father->pos)++;
		if(father->left!=NULL) insert(father->left,n);
		else father->left=new leaf(n);
	}
	else
	{
		if(father->right!=NULL) insert(father->right,n);
		else father->right=new leaf(n);
	}
}

void query(leaf *father,int n)
{
	int temp=n-1;
	if(father->pos>temp) query(father->left,n);
	else if(father->pos==temp) printf("%d\n",father->num);
	else query(father->right,n-father->pos-1);
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int all;
	scanf("%d",&all);
	while(all--)
	{
		int ask;
		scanf("%d",&ask);
		ask--;
		char cmd[10];
		int n;
		scanf("%s%d",cmd,&n);
		leaf *root=new leaf(n);
		printf("Case #%d:\n",counter++);
		while(ask--)
		{
			scanf("%s%d",cmd,&n);
			if(*cmd=='A') insert(root,n);
			else query(root,n);
		}
		root->~leaf();
	}
	return 0;
}