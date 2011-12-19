#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int score[30]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10,0,0,0,0};
int pos[30];
int sharp;

typedef struct word
{
	int wordlist[30];
	char w[30];
	int sc;
	
	void setscore()
	{
		sc=0;
		scanf("%s",w);
		for(int i=0;w[i]!='\0';i++)
		{
			if(w[i]>='a'&&w[i]<='z') w[i]=w[i]-'a'+'A';

			wordlist[w[i]-'A']++;
			sc+=score[w[i]-'A'];
		}
	}
	
	int minus(int sharp)
	{
		int ans=0;
		int res=0;
		for(int i=0;i<26;i++)
		{
			if(pos[i]-wordlist[i]<0) res+=pos[i]-wordlist[i];
			ans+=min(wordlist[i],pos[i])*score[i];
		}
		if(res+sharp>=0) return ans;
		else return -99;
	}
}word;

word array[25010];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(pos,0,sizeof(pos));
		memset(array,0,sizeof(array));
		sharp=0;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) array[i].setscore();
		int ask;
		scanf("%d",&ask);
		char ans[30];
		while(ask--)
		{
			scanf("%s",ans);
			if(*ans=='#') sharp++;
			else pos[*ans-'A']++;
		}
		
		memset(ans,0,sizeof(ans));
		int res=-1;
		for(int i=0;i<n;i++)
		{
			int temp=array[i].minus(sharp);
			if(temp>res)
			{
				res=temp;
				strcpy(ans,array[i].w);
			}
		}
		printf("%s %d\n",ans,res);
	}
	return 0;
}
	
