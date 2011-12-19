#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char key[26][1010];

int main()
{
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		memset(key,0,sizeof(key));
		int cmd;
		scanf("%d",&cmd);
		scanf("\n");
		int max=0;
		while(cmd--)
		{
			char ch;
			int start,end;
			
			scanf("%c%d%d",&ch,&start,&end);
			if(max<end) max=end;
			for(int i=start;i<end;i++)
			{
				key[ch-'A'][i]=(!key[ch-'A'][i]);
			}
			scanf("\n");
		}
		
		for(int i=0;i<max+5;i++)
		{
			int sum=0;
			for(int k=0;k<26;k++)
			{
				sum+=key[k][i];
			}
			if(sum>0) printf("%c",'A'+sum-1);
		}
		printf("\n");
	}
	return 0;
}