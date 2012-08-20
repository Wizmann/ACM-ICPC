//Result: wizmann	3750	Accepted	172K	0MS	C++	974B

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 65
#define lowbit(x) (x&(-x))
typedef struct string
{
	char name[20];

	inline void setstr()
	{
		scanf("%s",name);
	}
}string;

int n,st,s;
string child[N];
int baum[N];

void init()
{
	for(int i=1;i<=n;i++) baum[i]=lowbit(i);
}

int sum(int pos)
{
	int res=0;
	while(pos>0)
	{
		res+=baum[pos];
		pos-=lowbit(pos);
	}
	return res;
}

int find(int val)
{
	int l=1,r=n;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(sum(m)>=val) r=m-1;
		else l=m+1;
	}
	return l;
}

void letout(int pos)
{
	while(pos<N)
	{
		--baum[pos];
		pos+=lowbit(pos);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) child[i].setstr();
	scanf("%d,%d",&st,&s);
	init();
	int t;
	for(int i=0;i<n;i++)
	{
		st=((st+s-2)%(n-i)+(n-i))%(n-i)+1;
		//printf("ST=%d\n",st);
		t=find(st);
		//printf("T=%d\n",t);
		puts(child[t].name);
		letout(t);
	}
	return 0;
}
