//Result:wizmann	3371	Accepted	704K	0MS	G++	1699B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

//Test data:
//A. Ole drei end dead fucked. AES. DES. Maerlyn's. Gute. TTOLE.

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

#define EOS 1
//The end of sentence

#define VOVEL 2
//The vovel

#define ASC 256
#define BUFFER 128

char mark[ASC];

void init()
{
	memset(mark,0,sizeof(mark));
	mark['a']=mark['e']=mark['i']=mark['o']=mark['u']=mark['y']=VOVEL;
	mark['.']=mark['!']=mark['?']=mark[':']=mark[';']=EOS;
}

int sentence,word,vovel;


void check(char* buffer)
{
	int res=0;
	int len=strlen(buffer);
	if(mark[buffer[len-1]]==EOS)
	{
		sentence++;
		buffer[len-1]='\0';
		len--;
	}
	while(buffer[len-1]<'a' || buffer[len-1]>'z')
	{
		buffer[len-1]='\0';
		len--;
	}
	if(len<=3) res=1;
	else
	{
		if(buffer[len-2]=='e')
		{
			if(buffer[len-1]=='s' || buffer[len-1]=='d')
			{
				buffer[len-2]='\0';
				len-=2;
			}
		}
		else if(buffer[len-1]=='e')
		{
			if(buffer[len-2]!='l')
			{
				buffer[len-1]='\0';
				len--;
			}
		}
		for(int i=0;buffer[i];i++)
		{
			if(mark[buffer[i]]==VOVEL)
			{
				if(i==0) res++;
				else if(mark[buffer[i-1]]!=VOVEL) res++;
			}
		}
	}
	vovel+=res;
	word++;
}

double cal()
{
	return 206.835-1.015*((double)word/sentence)-84.6*((double)vovel/word);
}

int main()
{
	freopen("input.txt","r",stdin);
	char buffer[BUFFER];
	init();
	sentence=word=vovel=0;
	while(scanf("%s",buffer)!=EOF)
	{
		for(int i=0;buffer[i];i++)
		{
			if(buffer[i]>='A' && buffer[i]<='Z')
			{
				buffer[i]=buffer[i]-'A'+'a';
			}
		}
		check(buffer);
	}
	printf("%.2f\n",cal());
	return 0;
}

