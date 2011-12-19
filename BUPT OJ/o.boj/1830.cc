#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm> 

using namespace std;

const int shelf[]={0,2,3,5,8,10,11,13,14,15,16,17,18,19,21,22,24,25,26,27,29,30,33,34,35,38,39,41,47,49,50,60,80}; 

int main()
{
	int n;
	scanf("%d",&n);
	int a=1,b=32,mid;
	int res=lower_bound(shelf,shelf+32,n)-shelf;
	if(shelf[res]>n) res=shelf[res-1];
	else res=shelf[res];
	printf("2 ");
	if(res!=shelf[a]) printf("80 ");
	if(res!=shelf[b])
	{	
		do
		{
			mid=(a+b+1)/2;
			printf("%d ",shelf[mid]);
			if(shelf[mid]<n) a=mid;
			else b=mid;
		}while(shelf[mid]!=res);
		printf("\n");
	}
	return 0;
}
		
		
