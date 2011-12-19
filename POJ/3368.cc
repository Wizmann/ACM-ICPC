//Result: Wizmann	3368	Accepted	9184K	532MS	C++	1542B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#define max(a,b) (a>b?a:b)
#define SIZE 100100
#define log2(x) (log(x)/log(2.0)) //WA Point Fxxk Fxxk Fxxking!!!!

int code[SIZE];
int val[SIZE];
int left[SIZE];
int maxi[SIZE][20];

int n,ask,nr;

void init()
{
	memset(maxi,0,sizeof(maxi));
	for(int i=1;i<=nr;i++) maxi[i][0]=val[i];
	int m=floor(log2(double(nr)));
	for(int i=1;i<=m;i++)
	{
		for(int j=nr;j>=1;j--)
		{
			maxi[j][i]=maxi[j][i-1];
			if(j+(1<<(i-1))<=n) maxi[j][i]=max(maxi[j][i],maxi[j+(1<<(i-1))][i-1]);
		}
	}
}

int query(int l,int r)
{
	int m=floor(log2(double((r-l+1))));
	return max(maxi[l][m], maxi[r-(1<<m)+1][m]);
}
	

int main()
{
	while(scanf("%d",&n),n)
	{
		memset(code,0,sizeof(code));
		memset(val,0,sizeof(val));
		memset(left,0,sizeof(left));
		scanf("%d",&ask);
		int now=INT_MAX,t,num=0;
		nr=0;
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			if(now==t)
			{
				num++;
				code[i]=nr;
			}
			else
			{
				now=t;
				val[nr]=num;
				nr++;
				code[i]=nr;
				num=1;
				if(i==n) flag=true;
			}
		}
		if(!flag) val[nr]=num;
	
		for(int i=1;i<=nr;i++) left[i]+=left[i-1]+val[i];
		int a,b;
		init();
		while(ask--)
		{
			scanf("%d%d",&a,&b);
			int l=code[a],r=code[b];
			int res=-1;
			if(l+1<=r-1) res=query(l+1,r-1);//This is the WA point,too...
			if(r>l)
			{
				res=max(res,left[l]-a+1);
				res=max(res,b-left[r]+val[r]);
			}
			else res=max(res,b-a+1);
			printf("%d\n",res);
		}
	}
	return 0;
}
