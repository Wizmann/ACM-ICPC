#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <iostream>

const int SIZE=300000005;

using namespace std;

bitset<SIZE> prim;

int main()
{
	//freopen("e.txt","r",stdin);
	int l,r;
	scanf("%d%d",&l,&r);
	prim.set();
	for(int i=3;i*i<=r;i+=2)
	{
		if(prim[i]) for(int j=i*i;j<=r;j+=(i<<1)) prim[j]=0;
	}
	int ans=0;
	if(l<=2&&r>=2) ans++;
	for(int i=5;i<=r;i+=4)
	{
		if(i>=l&&prim[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
