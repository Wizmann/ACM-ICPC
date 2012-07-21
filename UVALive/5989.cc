//Result:1027640	5989	Here Be Dragons!	Accepted	C++	0.008	2012-07-02 12:37:24
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
	int T;
	char str[1024];
	input(T);
	while(T--)
	{
		bool flag=true;
		scanf("%s",str);
		for(int i=0;str[i];i++)
		{
			if(str[i]=='D')
			{
				print("You shall not pass!");
				flag=false;
				break;
			}
		}
		if(flag) print("Possible");
	}
	return 0;
}
		
