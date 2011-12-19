#include <iostream>
#include <cstdio>

using namespace std;

#define N 100+10

char city[N][N];
int road[N];

int search(int n)
{
	if(!road[n]||road[n]==n) return n;
	else return road[n]=search(road[n]);
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int n,m;
	scanf("%d%d",&n,&m);
	int h1,h2,h3;
	while(m--)
	{
		scanf("%d%d%d",&h1,&h2,&h3);
		if(h1) city[h2][h3]=city[h3][h2]=0;
		else city[h2][h3]=city[h3][h2]=1;
	}
	for(int i=1;i<=n;i++) road[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(city[i][j]) road[search(j)]=search(i);
		}
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&h1,&h2);
		if(search(h1)==search(h2)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}