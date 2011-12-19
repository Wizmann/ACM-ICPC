#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
	char name[15];
	tree *Left;
	tree *Right;
	
	tree()
	{
		memset(name,0,sizeof(name));
		Left=NULL;
		Right=NULL;
	}
	
	tree operator = (const char* right)
	{
		strcpy(name,right);
		return *this;
	}
	
	bool operator > (const char* right)
	{
		if(strcmp(name,right)==1) return true;
		else return false;
	}
	
	bool operator < (const char *right)
	{
		if(strcmp(name,right)==-1) return true;
		else return false;
	}
	
	bool operator == (const char *right)
	{
		if(strcmp(name,right)==0) return true;
		else return false;
	}
}tree;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	tree *root=new tree;
	char string[15];
	scanf("%s",string);
	*root=string;
	tree *head=root;
	for(int i=1;i<n;i++)
	{
		scanf("%s",string);
		tree *ttree=new tree;
		*ttree=string;
		while(1)
		{
			if(*head>string)
			{
				if(head->Right!=NULL) head=head->Right;
				else
				{
					head->Right=ttree;
					break;
				}
			}
			else
			{
				if(head->Left!=NULL) head=head->Left;
				else
				{
					head->Left=ttree;
					break;
				}
			}
		}
		head=root;
	}
	
	int m;
	scanf("%d",&m);
 	head=root;
	for(int i=0;i<m;i++)
	{
		scanf("%s",string);
		while(head!=NULL)
		{
			if(*head<string) head=head->Left;
			else if(*head>string) head=head->Right;
			else if(*head==string)
			{
				printf("YES\n");
				break;
			}
		}
		if(head==NULL) printf("NO\n");
		head=root;
	}
	return 0;
}