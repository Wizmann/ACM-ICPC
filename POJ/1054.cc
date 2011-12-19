//Result:wizmann	1054	Accepted	3236K	1438MS	C++	1403B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <bitset>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SIZE 5000

typedef struct node
{
	short x,y;

	inline void setnode(short a,short b){x=a;y=b;}
}node;

node pnt[SIZE];
std::bitset<SIZE> dp[SIZE];

int r,c;
int n,ans;

int cmp(const void *a,const void *b)
{
	if(((node*)a)->x==((node*)b)->x) return ((node*)a)->y-((node*)b)->y;
	return ((node*)a)->x-((node*)b)->x;
}

bool oor(int x,int y)
{
	if(x<=0||x>c) return true;
	else if(y<=0||y>r) return true;
	else return false;
}

int jump(int st,int end)
{
	int res=2;
	
	int dx=pnt[end].x-pnt[st].x;
	int dy=pnt[end].y-pnt[st].y;
	int tx=pnt[end].x;
	int ty=pnt[end].y;
	if(oor(tx+(ans-1)*dx,ty+(ans-1)*dy)) return res;
	if(!oor(pnt[st].x-dx,pnt[st].y-dy)) return res;
	while(!oor(dx+tx,dy+ty))
	{
		if(dp[ty+dy][tx+dx])
		{
			tx+=dx;
			ty+=dy;
			res++;
		}
		else return 0;
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	short a,b;
	scanf("%d%d%d",&r,&c,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%hd%hd",&a,&b);
		pnt[i].setnode(b,a);
		dp[a][b]=1;
	}
	qsort(pnt,n,sizeof(node),cmp);

	ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			ans=max(ans,jump(i,j));
		}
	}

	if(ans<3) puts("0");
	else printf("%d\n",ans);
	
	printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
