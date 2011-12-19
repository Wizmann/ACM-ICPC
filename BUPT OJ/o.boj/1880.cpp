#include <stdio.h>
#include <stdlib.h>

int arena(int *array,int n)
{
	int big=array[0];
	for(int i=1;i<n;i++)
	{
		if(array[i]>big) big=array[i];
	}
	return big;
}

int main()
{
	int n;
	scanf("%d",&n);
	int *input=new int[n];
	for(int i=0;i<n;i++) scanf("%c",&input[i]);
	
	int big=arena(input,n);
	
	int *number=new int[big];
	//我承认我的算法很DT。。。
	for(int i=1;i<big;i++)
	{
		for(int j=0;j<)
	} 
	
}