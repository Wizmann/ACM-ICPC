#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define eps 1e-6

const double PI=3.141592653589793238462643383279502884197169399;

double pie[10010];
int n,f;

bool judge(double r)
{
	double rest=pie[0];
	int ans=0;
	for(int i=0;i<n;/*Nope*/)
	{
		if(rest>eps)
		{
			if(rest>r)
			{
				rest-=r;
				ans++;
			}
			else rest=pie[++i];
		}
		else rest=pie[++i];
	}
	
	if(ans>f) return true;
	else return false;
}			

int main()
{
	freopen("input.txt","r",stdin);
	
	int t,ri;
	double high,low,mid;
	scanf("%d",&t);
	while(t--)
	{
		memset(pie,0,sizeof(pie));
		low=0;
		high=0;
		scanf("%d%d",&n,&f);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&ri);
			pie[i]=(double)ri*ri*PI;
			if(pie[i]>high) high=pie[i];
		}
		
		while(high-low>1e-4)
		{
			mid=(high+low)/2;
			if(judge(mid)) low=mid;
			else high=mid;
		}

		printf("%.4f\n",mid);
	}
	return 0;
}
