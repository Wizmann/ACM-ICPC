//Result:wizmann	3318	Accepted	6104K	1563MS	C++	872B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#define SIZE 505
#define llint long long
llint a[SIZE][SIZE],b[SIZE][SIZE],c[SIZE][SIZE];
int n;

bool check(int x,int y)
{
	for(int i=0;i<n;i++)
	{
		c[y][x]-=a[y][i]*b[i][x];
	}
	return !c[y][x];
}

int main()
{
	srand(time(NULL));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) scanf("%lld",&a[i][j]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) scanf("%lld",&b[i][j]);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) scanf("%lld",&c[i][j]);
	}
	
	int x,y;
	bool flag=true;
	for(int i=0;i<SIZE*24;i++)
	{
		x=rand()%n;
		y=rand()%n;
		//printf("%d %d\n",x,y);
		if(!c[y][x]) continue;
		if(!check(x,y))
		{
			flag=false;
			break;
		}
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}
