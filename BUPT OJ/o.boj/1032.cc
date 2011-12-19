#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int array[50100];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(array,0,sizeof(array));
		int n,t,size;
		scanf("%d",&n);
		scanf("%d",array);
		size=1;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&t);
			int *p=upper_bound(array,array+size,t);
			if(p==array+size)
			{
				*(array+size)=t;
				size++;
			}
			else *p=t;
		}
		
		printf("%d\n",size);
	}
	return 0;
}
			
	
