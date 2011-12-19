#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	float *array=(float*)malloc(sizeof(float)*n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		array[i]=a+(float)b/1000;
	}
	int counter=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(array[i]>array[j])
			{
				float temp;
				temp=array[i];array[i]=array[j];array[j]=temp;
				counter++;
			}
		}
	}
	printf("%d\n",counter);
	return 0;
}