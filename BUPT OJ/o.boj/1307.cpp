#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int flag=0;

typedef struct tree
{
	int num;
	tree *left;
	tree *right;
	
	tree()
	{
		num=-1;
		left=NULL;
		right=NULL;
	}
	
	void settree(int n)
	{
		num=n;
	}
}tree;

void treecreat(int f,int n,int lr,tree *head)
{
	if(head->num==f)
	{
		if(lr==0)//Left Tree
		{
			head->left=new tree;
			head->left->settree(n);
			return;
		}
		else//Right Tree
		{
			head->right=new tree;
			head->right->settree(n);
			return;
		}
	}
	else
	{
		if(head->left!=NULL) treecreat(f,n,lr,head->left);
		if(head->right!=NULL) treecreat(f,n,lr,head->right);
	}
}

void view(tree *head)
{
	if(flag==0)
	{
		printf("%d",head->num);
		flag=1;
	}
	else printf(" %d",head->num);
	
	if(head->left!=NULL) view(head->left);
	if(head->right!=NULL) view(head->right);
}

void del(tree *head)
{
	if(head->left!=NULL) delete head->left;
	if(head->right!=NULL) delete head->right;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		flag=0;
		int leaf;
		scanf("%d",&leaf);
		tree *root=new tree;
		int temp;
		scanf("%d",&temp);
		root->settree(temp);
		for(int i=0;i<leaf-1;i++)
		{
			int f,n,lr;
			scanf("%d%d%d",&f,&n,&lr);
			treecreat(f,n,lr,root);
		}
		
		view(root);
		printf("\n");
		
		del(root);
		delete root;
	}
	return 0;
}