#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	
	int array[320];
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	sort(array,array+n);
	printf("%d\n",array[k-1]);
	return 0;
}