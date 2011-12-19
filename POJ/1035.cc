#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

int dp[20][20];
std::queue<int> q;

inline void clear()
{
	while(!q.empty()) q.pop();
}

typedef struct word
{
	char str[20];
	int len;
	
	void setword(char *p)
	{
		memcpy(str,p,sizeof(str));
		len=strlen(str);
	}
	
	int check(char *p,int l)
	{
		if(abs(len-l)>1) return -1;//不相似
		int pos,i;
		if(len==l)
		{
			pos=0,i=0;
			while(i<l)
			{
				if(p[i+pos]==str[i+pos]) i++;
				else
				{
					if(!pos) pos++;
					else return -1;//不相似
				}
			}
			if(pos) return 0;//相似
			else return 1;//完全相同
		}
		else if(len>l)
		{
			pos=0,i=0;
			while(i<l)
			{
				if(p[i]==str[i+pos]) i++;
				else
				{
					if(!pos) pos++;
					else return -1;
				}
			}
			return 0;
		}
		else
		{
			pos=0,i=0;
			while(i<len)
			{
				if(p[i+pos]==str[i]) i++;
				else
				{
					if(!pos) pos++;
					else return -1;
				}
			}
			return 0;
		}
	}
		
}word;

word dict[10110];

int main()
{
	freopen("input.txt","r",stdin);
	char temp[20];
	int pos=0,ans,top;
	scanf("%s",temp);
	while(strcmp(temp,"#")!=0)
	{
		dict[pos].setword(temp);
		pos++;
		scanf("%s",temp);
	}
	scanf("%s",temp);
	while(strcmp(temp,"#")!=0)
	{
		bool flag=false;
		printf("%s",temp);
		clear();
		for(int i=0;i<pos;i++)
		{
			ans=dict[i].check(temp,strlen(temp));
			if(ans==1)
			{
				printf(" is correct\n");
				flag=true;
				break;
			}
			else if(ans==0) q.push(i);
		}
		if(!flag)
		{
			printf(":");
			while(!q.empty())
			{
				top=q.front();
				printf(" %s",dict[top].str);
				q.pop();
			}
			printf("\n");
		}
		scanf("%s",temp);
	}
	return 0;
}
