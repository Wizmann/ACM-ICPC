#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

int queue[30];
int sort[30];

int main()
{
	//freopen("input.txt","r",stdin);
	memset(queue,0,sizeof(queue));
	memset(sort,0,sizeof(sort));
	int n;
    scanf("%d",&n);
    scanf("\n");
    for(int i=0;i<n;i++)
    {
    	int num;
    	scanf("%d",&num);
    	scanf("\n");
    	for(int j=0;j<num;j++)
    	{
    		char ch;
	    	scanf("%c",&ch);
	    	queue[ch-'a']++;
	    }
	    memcpy(sort,queue,sizeof(queue));
	    qsort(sort,30,sizeof(int),comp);
	    for(int j=0;j<30;j++)
	    {
    		if(queue[j]==*sort)
			{
				printf("%c\n",j+'a');
				break;
			}
    	}
    	memset(queue,0,sizeof(queue));
    	memset(sort,0,sizeof(sort));
    }
    return 0;
}
