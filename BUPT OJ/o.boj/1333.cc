#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[1010];

int search(int n)
{
	if(array[n]==n) return n;
	else return array[n]=search(array[n]);
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int place,bri;
	scanf("%d%d",&place,&bri);
	
	/*INIT*/
	for(int i=0;i<=place+5;i++) array[i]=i;
	int hand1,hand2;
	int need=0;
	for(int i=0;i<bri;i++)
	{
		scanf("%d%d",&hand1,&hand2);
		if(search(hand1)!=search(hand2))
		{
			need++;
			array[search(hand2)]=search(hand1);
		}
	}
	
	printf("%d\n",bri-need);
	return 0;
}
