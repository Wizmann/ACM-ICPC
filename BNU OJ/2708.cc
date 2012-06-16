//Result:Wizmann	Accepted	GNU C++	100 ms	1252 KB	[ 498 B ]	
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 24

int zwei[SIZE],drei[SIZE];

void init()
{
	memset(zwei,0,sizeof(zwei));
	memset(drei,0,sizeof(drei));
	for(int i=1;i<SIZE;i++)
	{
		zwei[i]=1+(drei[i-1]<<1);
		drei[i]=(drei[i-1]<<1)+2+zwei[i-1];
	}
}


int main()
{
	int n;
	init();
	input(n);
	print(drei[n]);
	return 0;
}
