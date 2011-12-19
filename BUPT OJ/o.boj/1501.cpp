#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int queue[51000];
int melo[51000];

int search(int n)
{
	if(queue[n]==n) return n;
	else return queue[n]=search(queue[n]);
}

void set(int hand1,int hand2)
{
	queue[search(queue[hand1])] = queue[search(queue[hand2])];
}


int main()
{
	int level,color;
	scanf("%d%d",&level,&color);
	while(level!=0&&color!=0)
	{
		for(int i=1;i<=color;i++) queue[i]=i;
		
		for(int i=0;i<level;i++) scanf("%d",&melo[i]);
		
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int hand1,hand2;
			scanf("%d%d",&hand1,&hand2);
			set(hand1,hand2);
		}
		
		int sum=1;
		for(int i=1;i<level;i++) if( search(melo[i-1]) != search(melo[i]) ) sum++;

		printf("%d\n",sum);

		scanf("%d%d",&level,&color);
	}
	return 0;
}