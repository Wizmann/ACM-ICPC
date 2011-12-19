#include <cstdio>
#include <cstdlib>
#include <cstring>

int count(int x)
{
	int res=0;
	while(x)
	{
		if(x%10==9) res++;
		else break;
		x/=10;
	}
	return res;
}	

int main()
{
	freopen("input.txt","r",stdin);
	
	int low,high,temp,num,res;
	while(scanf("%d%d",&low,&high)!=EOF)
	{
		res=-1;
		num=-1;
		for(int i=high;i>=low;i--)
		{
			temp=count(i);
			if(temp>res)
			{
				res=temp;
				num=i;
			}
		}
		
		printf("%d\n",num);
	}
	return 0;
}
