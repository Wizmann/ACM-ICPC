#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct leaf
{
	char cmd[25];
	char val[25];
	leaf *L;
	leaf *R;	
	leaf()
	{
		memset(cmd,0,sizeof(cmd));
		memset(cmd,0,sizeof(val));
		L=NULL;R=NULL;
	}
	
	leaf operator = (const leaf& right)
	{
		strcpy(cmd,right.cmd);
		strcpy(val,right.val);
		return *this;
	}
	
	/*
	bool operator > (const char *com)
	{
		if ( strcmp(cmd,com)>0 ) return true;
		else return false;
	}
	
	bool operator < (const char *com)
	{
		if ( strcmp(cmd,com)<0 ) return true;
		else return false;
	}
	
	bool operator == (const char *com)
	{
		if ( strcmp(cmd,com)==0 ) return true;
		else return false;
	}*/
	
	bool operator == (const leaf& right) const
	{
		if (strcmp(right.cmd,cmd)==0) return true;
		else return false;
	}
	
	bool operator >(const leaf& right) const
	{
		if ( strcmp(cmd,right.cmd)>0 ) return true;
		else return false;
	}
	
	bool operator <(const leaf& right) const
	{
		if( strcmp(cmd,right.cmd)<0) return true;
		else return false;
	}	

}leaf;

leaf *creat(char* com,char *v)
{
	leaf *ret=new leaf;
	strcpy(ret->cmd,com);
	strcpy(ret->val,v);
	ret->L=NULL;
	ret->R=NULL;
	return ret;		
}

void mod(char *temp,leaf *a)
{
	char *p=temp;
	int i=0;
	while(*p!='=')
	{		
		a->cmd[i++]=*p>='A'&&*p<='Z'?*p+'a'-'A':*p;
		p++;
	}
	a->cmd[i]='\0';i=0;p++;
	while(*p!='\0'&&*p!='\n')
	{
		a->val[i++]=*p;
		p++;
	}
	a->val[i]='\0';
}

void alpha(char *temp)
{
	char *p=temp;
	while(*p!='\0')
	{
		*p=*p>='A'&&*p<='Z'?*p+'a'-'A':*p;
		p++;
	}
}

void BST_s(char *com,leaf *head)
{
	if(head==NULL)
	{
		//printf("HEAD==NULL");
		printf("\n");
		return;		
	} 
	int flag=strcmp(com,head->cmd);
	if(flag==0)
	{
		printf("%s\n",head->val);
		return;
	}
	else if(flag>0) BST_s(com,head->R);
	else BST_s(com,head->L);
}

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	int i=0;
	scanf("%d",&n);
	leaf root;
	char temp[100];
	turf:
	gets(temp);i++;
	if(*temp=='#'||*temp=='\n'||*temp=='\0') goto turf;
	mod(temp,&root);	
	for(;i<=n;i++)
	{
		gets(temp);	
		if(*temp=='#'||*temp=='\n'||*temp=='\0') continue;
		leaf *p=new leaf;
		mod(temp,p);
		leaf* head = &root;
		leaf* ins = NULL;
		int flag=0;
		while(head!=NULL)
		{			
			ins=head;
			//		RIGHT BIG (1)
			//ROOT<
			//		LEFT  SMALL (-1)
			if(*p>*head)
			{
				head=head->R;
				flag=1;
			}
			else if(*p<*head)
			{
				head=head->L;
				flag=-1;
			}
			else
			{
				*head=*p;
				head=NULL;
				flag=0;
			}
		}
		
		if(flag==1)
		{
			ins->R=p;
			//printf("RIGHT:%s\n",ins->R->cmd);
		}
		if(flag==-1)
		{
			ins->L=p;
			//printf("LEFT:%s\n",ins->L->cmd);
		}

	}
	
	while(scanf("%s",temp)!=-1)
	{
		if(*temp=='\n') continue;
		alpha(temp);
		//printf("%s",temp);
		BST_s(temp,&root);
	}	
	return 0;
}

