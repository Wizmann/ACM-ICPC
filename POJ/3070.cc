#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 10000

const int mat[2][2]={{1,1},{1,0}};

int res[2][2];

void mul(int a[][2],const int b[][2])
{
	int temp[4];
	temp[0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
	temp[1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
	temp[2]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
	temp[3]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;
	
	a[0][0]=temp[0];
	a[0][1]=temp[1];
	a[1][0]=temp[2];
	a[1][1]=temp[3];
}

void fab(unsigned n)
{
	if(n==2) mul(res,res);
	else if(n==1) return;
	else
	{
		if(n%2==0)
		{
			fab(n/2);
			mul(res,res);
		}
		else
		{
			fab(n/2);
			mul(res,res);
			mul(res,mat);
		}
	}
}

int main()
{	
	unsigned n;
	scanf("%d",&n);
	while(n!=-1)
	{
		if(!n)
		{
			printf("0\n");
			scanf("%d",&n);
			continue;
		}
		memcpy(res,mat,sizeof(mat));
		fab(n);
		printf("%d\n",res[0][1]);
		scanf("%d",&n);
	}
	return 0;
}
