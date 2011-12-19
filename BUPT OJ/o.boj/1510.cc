#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct leaf
{
	int n;
	int nr;
	leaf *left;
	leaf *right;
	
	leaf()
	{
		nr=0;
		left=NULL;
		right=NULL;
	}
	
	void setleaf(int num)
	{
		n=num;
	}
	
	void del()
	{
		delete this->left;
		delete this->right;
		delete this;
	}
}leaf;

void insert(leaf *root,int num)
{
	if(root->n>num)
	{
		if(root->left==NULL)
		{
			root->left=new leaf;
			root->left->setleaf(num);
			(root->nr)++;
		}
		else
		{
			insert(root->left,num);
			(root->nr)++;
		}
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=new leaf;
			root->right->setleaf(num);
		}
		else insert(root->right,num);
	}
}

int getmid(leaf *root,int n)
{
	if(root->nr==n-1) return root->n;
	else if(n-1>root->nr) return getmid(root->right,n-1-root->nr);
	else return getmid(root->left,n);
}

int main()
{
	int ask;
	while(scanf("%d",&ask)!=EOF&&ask)
	{
		int hand1,hand2;
		int num=1;
		ask--;
		scanf("%d%d",&hand1,&hand2);
		leaf *root=new leaf;
		root->setleaf(hand2);
		while(ask--)
		{
			scanf("%d",&hand1);
			if(hand1==1)
			{
				scanf("%d",&hand2);
				insert(root,hand2);
				num++;
			}
			else
			{
				if(num%2==0) printf("%.1lf\n",(double)(getmid(root,num/2+1)+getmid(root,num/2))/2);
				else printf("%d.0\n",getmid(root,num/2+1));
			}
				
		}
		
		root->del();
	}
	return 0;
}