//Result:wizmann	3748	Accepted	712K	0MS	G++	359B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
	int r,x,y;
	scanf("%x,%d,%d",&r,&x,&y);
	int a=~0;
	a^=(1<<x);
	r&=a;
	a=~0;
	a^=1<<(y-2);
	r&=a;
	r|=3<<(y-1);
	printf("%x\n",r);
	return 0;
}
