#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int prim(int n)
{
	if(n!=2&&n%2==0) return 0;
	else if(n!=3&&n%3==0) return 0;
	else
	{
		for(int i=3;i*i<=n+1;i+=2)
		{
			if(n%i==0) return 0;
		}
		return 1;
	}
}

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

typedef struct dance
{
	int dp[7][1000];
	int *p;
	
	dance()
	{
		memset(dp,0,sizeof(dp));
		p=NULL;
	}
	
	void push(int n)
	{
		*p=n;
		p++;
	}
	

	void setdance(int n)
	{
		dp[0][0]=n;
		for(int i=1;i<7;i++)
		{
			p=&dp[i][0];
			for(int k=0;k<100;k++)
			{
				if(dp[i-1][k])
				{
					for(int l=1;l<10;l++)
					{
						if(prim ( 10*dp[i-1][k] + l ) ) 
						{
							push( 10*dp[i-1][k]+l );
						}
					}
					
				}
				else break;
			}
		}
	}
}dance;

int *stack;
void stackpush(int n)
{
	*stack=n;
	stack++;
}

int main()
{	
	
	//freopen("input.txt","w",stdout);

	dance zwei,drei,sieben,fuenf;
	zwei.setdance(2);
	drei.setdance(3);
	fuenf.setdance(5);
	sieben.setdance(7);
	
	int n;
	scanf("%d",&n);
	while(n)
	{
		if(n==1)
		{
			printf("2\n3\n5\n7\n\n");
		}
		else
		{
			int temp[2000];
			stack=temp;
			memset(temp,0,sizeof(temp));
			
			for(int i=0;i<100;i++)
			{
				if(zwei.dp[n-1][i]) stackpush(zwei.dp[n-1][i]);
			}			
			
			for(int i=0;i<100;i++)
			{
				if(drei.dp[n-1][i]) stackpush(drei.dp[n-1][i]);
			}
			
			for(int i=0;i<100;i++)
			{
				if(fuenf.dp[n-1][i]) stackpush(fuenf.dp[n-1][i]);
			}		
			
			for(int i=0;i<100;i++)
			{
				if(sieben.dp[n-1][i]) stackpush(sieben.dp[n-1][i]);
			}
			
			qsort(temp,2000,sizeof(int),cmp);
			for(int i=0;i<2000;i++)
			{
				if(temp[i]) printf("%d\n",temp[i]);
			}
			
			printf("\n");
		}
		
		scanf("%d",&n);
	}
	return 0;
}