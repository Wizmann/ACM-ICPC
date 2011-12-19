//Result:Wizmann	2513	Accepted	17688K	1047MS	G++	1653B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MOD 757137

typedef struct node
{
	char color[12];
	int next;
	
	void setnode(char *s)
	{
		strcpy(color,s);
		next=-1;
	}
}node;

node stick[MOD+5];
int hash[MOD+5];
int n=1;
int SET[MOD+5];
int app[MOD+5];

int gethash(char *ch)
{
	long long res=0;
	long long t;
	while(*ch!='\0')
	{
		t=*ch;
		res=(res*29+*ch-'a')%MOD;
		ch++;
	}
	return res%MOD;
}

int getpos(char *s)
{
	int pos=gethash(s);
	if(hash[pos]==-1) return 0;
	else
	{
		pos=hash[pos];
		while(pos!=-1)
		{
			if(strcmp(s,stick[pos].color)==0) return pos;
			else pos=stick[pos].next;
		}
		return 0;
	}
}

int find(int n)
{
	if(SET[n]==n) return n;
	else return SET[n]=find(SET[n]);
}

int insert(char *s)
{
	stick[n].setnode(s);
	int pos=gethash(s);
	if(hash[pos]==-1) hash[pos]=n;
	else
	{
		int t=hash[pos];
		hash[pos]=n;
		stick[n].next=t;
	}
	return n++;
}

int main()
{
	freopen("input.txt","r",stdin);
	memset(hash,-1,sizeof(hash));
	char sa[12],sb[12];
	int a,b,father;
	for(int i=0;i<=MOD;i++) SET[i]=i;
	while(scanf("%s%s",sa,sb)!=EOF)
	{
		a=getpos(sa);
		if(!a) a=insert(sa);
		b=getpos(sb);
		if(!b) b=insert(sb);
		app[a]++;app[b]++;
		
		if(find(a)!=find(b))
		{
			SET[find(b)]=a;
			father=find(b);
		}
	}


	for(int i=0;i<=MOD;i++)
	{
		if(SET[i]!=i)
		{
			if(find(father)!=find(i))
			{
				puts("Impossible");	
				//printf("EXIT 1\n");
				exit(0);
			}
		}
	}
	
	int sum=0;
	for(int i=0;i<=MOD;i++)
	{
		if(app[i]%2!=0) sum++;
	}
	
	if(sum==0||sum==2) puts("Possible");
	else puts("Impossible");
	
	return 0;
}
