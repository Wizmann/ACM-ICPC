#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define LEN 60

typedef struct node
{
	char dna[70];
	
	inline void setnode()
	{
		scanf("%s",dna);
	}
	
	inline bool find(char *p)
	{
		if(strstr(dna,p)) return true;
		else return false;
	}
}node;

node array[12];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t,len;
	scanf("%d",&t);
	bool flag;
	char temp[LEN+10],ans[LEN+10];
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++) array[i].setnode();
		len=strlen(array[0].dna);
		for(int i=len;i>=3;i--)
		{
			for(int j=0;j<=len-i;j++)
			{
				flag=true;
				memset(temp,0,sizeof(temp));
				strncpy(temp,array[0].dna+j,i);
				for(int i=1;i<n;i++)
				{
					if(!array[i].find(temp))
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					if(strlen(ans)<3) memcpy(ans,temp,sizeof(ans));
					else if(strlen(temp)==strlen(ans)&&strcmp(ans,temp)>0) memcpy(ans,temp,sizeof(ans));
					else if(strlen(temp)>strlen(ans)) memcpy(ans,temp,sizeof(ans));
				}
			}
		}
		
		if(strlen(ans)>=3) puts(ans);
		else puts("no significant commonalities");
	}
	return 0;
}
	
