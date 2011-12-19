#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MOD 2458799
#define N 6
#define SIZE 299999

typedef struct node
{
	int a,b;
	bool flag;
}node;

node hashtable[299999+200];//299999 of 100000

long long gethash(int *array)
{
	std::sort(array,array+N);
	long long temp=0;
	for(int i=0;i<N;i++)
	{
		temp+=(long long)array[i]<<(i*3)%MOD;
	}
	if(temp<0) temp=0;
	return temp%SIZE;
}

int geta(int *array)
{
	int a=0;
	for(int i=0;i<N;i++)
	{
		a+=array[i];
		a%=MOD;
	}
	return a;
}

int getb(int *array)
{
	int b=0;
	b=(array[0] + array[2] + array[4])&(array[1] + array[3] + array[5]);
	return b;
}

int snow[10];

int main()
{
	freopen("input.txt","r",stdin);
	int n,a,b;
	long long pad;
	scanf("%d",&n);
	memset(hashtable,0,sizeof(hashtable));
	while(n--)
	{
		for(int i=0;i<N;i++) scanf("%d",snow+i);
		pad=gethash(snow);
		a=geta(snow);
		b=getb(snow);
		while(hashtable[pad].flag)
		{
			if(hashtable[pad].a==a&&hashtable[pad].b==b)
			{
				printf("Twin snowflakes found.\n");
				exit(0);
			}
			else pad++;
			if(pad>SIZE) pad=0;
		}
		
		hashtable[pad].a=a;
		hashtable[pad].b=b;
		hashtable[pad].flag=true;
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}
