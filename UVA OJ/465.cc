//Result:465	Overflow	Accepted	C++	0.008	2012-08-10 08:08:23
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 13000

typedef long long llint;

const long long MAX=2147483647LL;

bool check_too_big(char *a,llint &res)
{
	while(*a=='0') a++;
	if(strlen(a)>12) return true;
	else
	{
		if(sscanf(a,"%lld",&res)==EOF) res=0;
		if(res>MAX) return true;
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	char a[SIZE],b[SIZE],opt[4];
	llint lla,llb;
	bool biga,bigb;
	while(scanf("%s%s%s",a,opt,b)!=EOF)
	{
		printf("%s %s %s\n",a,opt,b);
		lla=llb=1;
		biga=bigb=false;
		if(check_too_big(a,lla))
		{
			puts("first number too big");
			biga=true;
		}
		if(check_too_big(b,llb))
		{
			puts("second number too big");
			bigb=true;
		}
		
		if( (biga || bigb) && lla && llb ) puts("result too big");
		else if( (biga || bigb) && *opt=='*' && (lla==0 || llb==0) )
		{
			//Result==0;
		}
		else
		{
			
			llint res=0;
			if(*opt=='+') res=lla+llb;
			else if(*opt=='*') res=lla*llb;
			else
			{
				while(1){/*看看有没有非法数据*/}
			}
			if(res>MAX) puts("result too big");
		}		
	}
	return 0;
	
}
