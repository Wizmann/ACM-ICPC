#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ALPHA 30

typedef struct node
{
	int next[ALPHA];
	char stop;
	int cnt;
	
	node()
	{
		memset(next,-1,sizeof(next));
		stop=0;
		cnt=0;
	}
}node;

typedef struct str
{
	char string[25];
}str;

node trie[1<<15];
str dict[1010];
int pad=0;
int pos;
int head[ALPHA];
char stack[25];
char *st;

inline void init()
{
	memset(stack,0,sizeof(stack));
	st=stack;
}

inline void push(char ch)
{
	*st=ch;
	st++;
}

inline void print()
{
	puts(stack);
}

void insert(char *word)
{
	char *p=word;
	pos=head[*p-'a'];
	if(pos==-1) head[*p-'a']=pos=pad++;
	p++;
	
	while(*p!='\0')
	{
		trie[pos].cnt++;
		int t;
		t=trie[pos].next[*p-'a'];
		if(t==-1) trie[pos].next[*p-'a']=pad++;
		pos=trie[pos].next[*p-'a'];
		p++;
	}
	trie[pos].stop=1;
	trie[pos].cnt++;
}

void search(char *word)
{
	printf("%s ",word);
	init();
	char *p=word;
	pos=head[*p-'a'];
	push(*p);
	p++;
	
	while(*p!=0)
	{
		//printf("%d\n",trie[pos].cnt);
		if(trie[pos].cnt==1)
		{
			print();
			return;
		}
		else
		{
			push(*p);
			pos=trie[pos].next[*p-'a'];
			p++;
		}
	}
	if(*p==0) puts(word);
}

int main()
{
	freopen("input.txt","r",stdin);
	memset(head,-1,sizeof(head));
	int n=0;
	while(scanf("%s",dict[n].string)!=EOF)
	{
		insert(dict[n].string);	
		n++;
	}
	for(int i=0;i<n;i++) search(dict[i].string);
	return 0;
}
