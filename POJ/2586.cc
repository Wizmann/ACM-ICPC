//Result:wizmann	2586	Accepted	396K	0MS	G++	782B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define abs(x) (x>0?x:-x)

int s,d;
int money[30];

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&s,&d)==2)
	{
		bool flag=true;
		int ans=-1<<20,num;
		for(int i=0;i<=5;i++)
		{
			int t=s*i-(5-i)*d;
			if(t<0&&t>ans){ans=t;num=i;}
		}
		if(ans<=-1<<20){puts("Deficit");continue;}
		for(int i=1;i<=num;i++) money[i]=s;
		for(int i=num+1;i<=5;i++) money[i]=-d;
		for(int i=6;i<=12;i++)
		{
			ans-=money[i-5];
			if(ans+s<0)
			{
				ans+=s;
				money[i]=s;
			}
			else
			{
				ans-=d;
				money[i]=-d;
			}
			//printf("%d\n",ans);
		}
		if(flag)
		{
			ans=0;
			for(int i=1;i<=12;i++) ans+=money[i];
			if(ans>=0) printf("%d\n",ans);
			else puts("Deficit");
		}
	}
	return 0;
}
			
