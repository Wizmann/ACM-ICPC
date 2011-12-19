#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phone
{
	char number[15];
	
	void setphone()
	{
		scanf("%s",number);
	}
}phone;

int cmp(const void *a,const void *b)
{
	phone *ta=(phone*)a;
	phone *tb=(phone*)b;
	return ( strcmp (ta->number,tb->number) );
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		int n;
		scanf("%d",&n);
		phone *array=new phone[n];
		
		for(int i=0;i<n;i++)
		{
			array[i].setphone();
		}
		qsort(array,n,sizeof(phone),cmp);		
		
		int flag=1;
		for(int i=1;i<n;i++)
		{
			int len=strlen(array[i-1].number);
			if(strncmp(array[i-1].number,array[i].number,len)==0) 
			{
				flag=0;
				break;
			}
		}
		
		if(flag) printf("YES\n");
		else printf("NO\n");
		
		delete [] array;
	}
	return 0;
}