#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define LEN 120
#define print(x) cout<<x<<endl

typedef struct node
{
	char dna[LEN];
	
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
	int n;
	int len;
	bool flag;
	char temp[LEN+10],ans[LEN+10];
	while(scanf("%d",&n)!=EOF)
	{
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++) array[i].setnode();
		len=strlen(array[0].dna);
		for(int i=len;i>=0;i--)
		{
			for(int j=0;j<=len-i;j++)
			{
				flag=true;
				memset(temp,0,sizeof(temp));
				strncpy(temp,array[0].dna+j,i);
				print(temp);
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
					if(strlen(ans)==0) memcpy(ans,temp,sizeof(ans));
					else if(strlen(temp)==strlen(ans)&&strcmp(ans,temp)>0) memcpy(ans,temp,sizeof(ans));
					else if(strlen(temp)>strlen(ans)) memcpy(ans,temp,sizeof(ans));
				}
			}
		}
		print(ans);
		printf("%d\n",strlen(ans));
	}
	return 0;
}
