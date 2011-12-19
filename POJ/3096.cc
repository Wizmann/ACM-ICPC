#include <cstdio>
#include <cstdlib>
#include <cstring>

char hash[30][30];
char str[80];

int main()
{
	freopen("input.txt","r",stdin);
	int len;
	while(1)
	{
next:	scanf("%s",str);
		len=strlen(str);
		if(*str!='*')
		{
			for(int i=1;i<len;i++)
			{
				memset(hash,0,sizeof(hash));
				for(int j=0;j+i<len;j++)
				{
					int a=str[j]-'A';
					int b=str[j+i]-'A';
					
					if(hash[a][b])
					{
						printf("%s is NOT surprising.\n",str);
						goto next;
					}
					else hash[a][b]=1;
				}
			}
			printf("%s is surprising.\n",str);
		}
		else break;
	}
	return 0;
}
	
