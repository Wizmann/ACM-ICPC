#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float win(float *a,float *b)
{
	float res=0;
	
	res+=a[0]*b[1];
	res+=a[1]*b[2];
	res+=a[2]*b[0];
	
	return res;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	float a[3],b[3];
	while(counter--)
	{
		for(int i=0;i<3;i++) scanf("%f",&a[i]);
		for(int i=0;i<3;i++) scanf("%f",&b[i]);
		
		printf("%.3f %.3f\n",win(a,b),win(b,a));
	}
	return 0;
}