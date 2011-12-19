#include <stdio.h>
#include <iostream>
#include <stream.h>

int main()
{
	int n,k;
	cin>>n>>k;
	int array[900];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	std::sort(array,array+n);
	printf("%d\n",array[n-k]);
	return 0;
}