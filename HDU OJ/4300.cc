//Result:2012-07-24 23:25:01	Accepted	4300	31MS	1100K	1380B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE=100000;

int next[SIZE+5];
char conv[32],anti[32];
char str[SIZE+5],mia[SIZE+5];
int len;

void kmp_get_next()
{
	next[0]=-1;
	for(int i=0,j=-1;i<len;i++,j++,next[i]=j)
	{
		while(j>=0 and str[i]!=str[j]) j=next[j];
	}
}

char decode(char x)
{
	return conv[x-'a'];
}

void make_anti()
{
	for(int i=0;conv[i];i++)
	{
		anti[conv[i]-'a']='a'+i;
	}
}

char encode(char x)
{
	return anti[x-'a'];
}

int slove()
{
	int i,j;
	i=j=0;
	while(i<len and j<len)
	{
		if(j==-1 or mia[i]==str[j])
		{
			i++;j++;
		}
		else
		{
			j=next[j];
		}
	}
	while(j>len/2) j=next[j];
	return j;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		memset(mia,0,sizeof(mia));
		memset(str,0,sizeof(str));
		memset(next,0,sizeof(next));
		scanf("%s",conv);
		scanf("%s",str);
		len=strlen(str);
		for(int i=0;str[i];i++)
		{
			mia[i]=decode(str[i]);
		}
		make_anti();
		kmp_get_next();
		int k=slove();
		for(int i=0;mia[i+k];i++)
		{
			printf("%c",str[i]);
		}
		for(int i=0;mia[i+k];i++)
		{
			printf("%c",encode(str[i]));
		}
		puts("");
	}
	return 0;
}
