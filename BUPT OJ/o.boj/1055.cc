#include <cstdio>
#include <iostream>

int dir[200];
char ant[200];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++) dir[i]=1;
	//1 is to right
	for(int i=1;i<=b;i++) dir[a+i]=-1;
	//-1 is to left
	
	scanf("\n");
	char ch;
	for(int i=0;i<a;i++)
	{
		scanf("%c",&ch);
		ant[a-i]=ch;
	}
	scanf("\n");
	for(int i=1;i<=b;i++)
	{
		scanf("%c",&ch);
		ant[a+i]=ch;
	}
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<a+b;i++)
		{
			if(dir[i]==1&&dir[i+1]==-1)
			{
				std::swap(ant[i],ant[i+1]);
				std::swap(dir[i],dir[i+1]);
				i++;
			}
		}
	}
	
	for(int i=1;i<=a+b;i++) printf("%c",ant[i]);
	printf("\n");
	
	return 0;
}
