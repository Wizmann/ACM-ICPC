#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct goods
{
	int price;
	int im;
	
	void setgoods(int a,int b)
	{
		price=a;
		im=b;
	}
}goods;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int money,n;
	scanf("%d%d",&money,&n);
	int *array=(int*)malloc(sizeof(int)*(money+5));

	goods *g=(goods*)malloc(sizeof(goods)*n);

	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[i].setgoods(a,b);
	}
	memset(array,0,sizeof(int)*(money+5));	
	for(int i=0;i<n;i++)
	{
		for(int k=money-g[i].price;k>=0;k--)
		{
			if(array[k]!=0||k==0) 
			{
				int in=array[k]+g[i].price*g[i].im;
				if(array[k+g[i].price]<in) array[k+g[i].price]=in;
			}
		}
	}
	
	int max=-1;
	for(int i=money-1;i>=0;i--)
	{
		if(array[i]>max) max=array[i];
	}
	printf("%d\n",max);
	return 0;	
}