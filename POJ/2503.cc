//Result: wizmann	2503	Accepted	4328K	875MS	G++	1262B	2011-05-02 16:10:14

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define SIZE 117311

typedef struct node
{
	char chn[15],eng[15];
	int next;
	
	void setnode(char *p)
	{
		sscanf(p,"%s%s",chn,eng);
		next=-1;
	}
}node;

int hash[SIZE+50];
node table[100010];

long long getres(char *p)
{
	long long res=0;
	for(/*Nope*/;*p!='\0';p++)
	{
		res+=( (*p << 4) ) ^ ( (*p + SIZE) >> 2 );
		res%=SIZE;
	}
	while(res<0) res+=SIZE;
	return res%SIZE;
}

void gethash(int n)
{
	long long res=getres(table[n].eng);
	
	if(hash[res]==-1) hash[res]=n;
	else
	{
		int t=hash[res];
		hash[res]=n;
		table[n].next=t;
	}
}

bool getword(char *p)
{
	long long res=getres(p);
	if(hash[res]==-1) return false;
	else
	{
		int t=hash[res];
		while(t!=-1)
		{
			if(strcmp(p,table[t].eng)==0)
			{
				puts(table[t].chn);
				return true;
			}
			else t=table[t].next;
		}
		return false;
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	memset(hash,-1,sizeof(hash));
	char input[150];
	int pos=0;
	while(1)
	{
		gets(input);
		if(*input=='\0') break;
		table[pos++].setnode(input);
	}
	
	for(int i=0;i<pos;i++) gethash(i);
	while(scanf("%s",input)!=EOF)
	{
		if(getword(input)==false) puts("eh");
	}
	
	return 0;
}
	
	
