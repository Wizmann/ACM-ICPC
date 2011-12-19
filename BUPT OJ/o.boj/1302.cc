#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 26
#define SIZE 800000

typedef struct node
{
	node *next[N];
	int cnt;

	node()
	{
		memset(next,0,sizeof(next));
		cnt=0;
	}
	
	void clr()
	{
		memset(next,0,sizeof(next));
		cnt=0;
	}
}node;

node trie[SIZE];
int pos=0;
char str[1<<15];

node* head=trie;

void ins(char *str)
{
	int len=strlen(str);
	
	node *ptr=head;
	int ch;
	
	for(int i=0;i<len;i++)
	{
		ch=str[i]-'a';
		if(ptr->next[ch]==NULL) ptr->next[ch]=&trie[++pos];
		
		ptr=ptr->next[ch];
	}
	(ptr->cnt)++;
}

int ask(char *str)
{
	int len=strlen(str);
	
	node *ptr=head;
	int ch;
	
	for(int i=0;i<len;i++)
	{
		ch=str[i]-'a';
		if(ptr->next[ch]==NULL) return 0;
		else ptr=ptr->next[ch];
	}
	return ptr->cnt;
}

int cas=0;

void init()
{
	for(int i=0;i<SIZE;i++) trie[i].clr();
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char temp[10];
	while(scanf("%s",str)!=EOF)
	{
		init();
		pos=0;
		printf("Case %d:\n",++cas);
		
		int len=strlen(str);
		
		for(int i=1;i<=8;i++)
		{
			for(int j=0;j<=len-i;j++)
			{
				strncpy(temp,str+j,i);
				temp[i]='\0';
				ins(temp);
			}
		}
		
		int n;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",temp);
			printf("%d\n",ask(temp));
		}
	}
	return 0;
}
		

		
			
