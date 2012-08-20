//Wizmann	2002	Accepted	188K	2235MS	C++	1509B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 3171

typedef struct node
{
	int x,y;
	int next;
	
	void setnode(int a,int b)
	{
		x=a;
		y=b;
		next=0;
	}
	
	bool equal(int a,int b)
	{
		if(x==a&&y==b) return true;
		else return false;
	}
}node;

short hash[SIZE];
node point[1010];

int gethash(int x,int y)
{
	long long res=x*x+y*y;
	while(res<0) res+=SIZE;
	return res%SIZE;
}

void intohash(int i)
{
	int pos=gethash(point[i].x,point[i].y);
	pos%=SIZE;
	if(hash[pos]==0) hash[pos]=i;
	else
	{
		int t=hash[pos];
		hash[pos]=i;
		point[i].next=t;
	}
}

bool find(int x,int y)
{
	int pos=gethash(x,y);
	if(hash[pos])
	{
		int t=hash[pos];
		while(t!=0)
		{
			if(point[t].equal(x,y)) return true;
			t=point[t].next;
		}
	}
	return false;
}
		

int main()
{
	freopen("input.txt","r",stdin);
	int n,a,b;
	while(scanf("%d",&n),n)
	{
		long long ans=0;
		memset(hash,0,sizeof(hash));
		memset(point,0,sizeof(point));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			point[i].setnode(a,b);
			intohash(i);
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int tx=point[i].x-point[j].x;
				int ty=point[i].y-point[j].y;
				int x3=-ty,y3=tx;
				if(find(x3+point[i].x,y3+point[i].y) && find(x3+point[j].x,y3+point[j].y)) ans++;
				
				x3=ty,y3=-tx;
				if(find(x3+point[i].x,y3+point[i].y) && find(x3+point[j].x,y3+point[j].y)) ans++;
			}
		}
		
		printf("%lld\n",ans/4);
	}
	return 0;
}
				
