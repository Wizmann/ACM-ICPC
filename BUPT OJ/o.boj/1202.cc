#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 40

long long plate[MAX];

inline void init()
{
	for(int i=1;i<=35;i++)
	{
		plate[i]=plate[i-1]+((long long)1<<(i-1));
		//printf("%lld\n",plate[i]);
	}
}

int search(int apple)
{
	int high=32,low=0;
	int mid=(high+low)/2;
	
	while(!(plate[mid]>apple&&plate[mid-1]<=apple))
	{
		if(plate[mid]>apple)
		{
			high=mid;
			mid=(high+low)/2;
		}
		else
		{
			low=mid;
			mid=(high+low)/2;
		}
	}
	return plate[mid-1]==apple?mid-1:mid;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	init();
	
	int apple,m;
	scanf("%d%d",&apple,&m);
	while(apple&&m)
	{
		int need=search(apple);
		if(need<=m) printf("YES\n");
		else printf("NO\n");		
		scanf("%d%d",&apple,&m);
	}	
	return 0;
}
