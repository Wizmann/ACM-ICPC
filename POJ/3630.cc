#include <cstdio>
#include <cstdlib>
#include <cstring>

#define START 0

typedef struct node
{
	int next[15];
	char stop;
}node;

node trie[60000];
char code[15];
int pad=0;

bool insert(char *word)
{
	char *p=word;
	int pos=trie[START].next[*p-'0'];
	if(pos==0)
	{
		trie[START].next[*p-'0']=pad;
		pos=pad++;
	}
	while(*p!='\0')
	{
		if(trie[pos].stop) return false;
		else
		{
			int t=trie[pos].next[*p-'0'];
			if(!t)
			{
				trie[pos].next[*p-'0']=pad;
				pos=pad++;
			}
			else pos=t;
			
			p++;
		}
	}
	trie[pos].stop=1;
	bool flag=true;
	for(int i=0;i<15;i++)
	{
		if(trie[pos].next[i]) flag=false;
	}
	return flag;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,n;
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		pad=1;
		memset(trie,0,sizeof(trie));
		flag=true;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",code);
			if(flag&&!insert(code))
			{
				flag=false;
				puts("NO");
			}
		}
		if(flag) puts("YES");
	}
	return 0;
}
		
