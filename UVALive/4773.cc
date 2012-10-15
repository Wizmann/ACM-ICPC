//Result:4773	YY and YY Again	Accepted	C++	0.008	2012-10-13 06:10:00
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512

int main()
{
	freopen("input.txt","r",stdin);
	char str[SIZE];
	while(1)
	{
		bool _EOF=false;
		while(1)
		{
			if(gets(str)==NULL)
			{
				_EOF=true;
				break;
			}
			else
			{
				if(*str!='\0'&& *str!='\n') break;
			}
		}
		if(_EOF) break;
		int sum=0;
		for(int i=0;str[i];i++)
		{
			if(str[i]>='A' && str[i]<='Z') sum+=str[i]-'A'+1;
		}

		if(sum>100) puts("INVALID");
		else print(sum);
	}
	return 0;
}

