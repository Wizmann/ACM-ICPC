//Result:wizmann	3749	Accepted	692K	0MS	G++	694B
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define BUF 1024



inline char encode(char x)
{
	if(x>='A' && x<='Z')
	{
		int next=(x-'A'-5+26)%26;
		return next+'A';
	}
	else return x;
}


int main()
{
	freopen("input.txt","r",stdin);
	char buffer[BUF];
	while(1)
	{
		gets(buffer);
		if(!strcmp(buffer,"ENDOFINPUT")) break;
		else
		{
			if(!strcmp(buffer,"START") || !strcmp(buffer,"END"))
			{
				continue;
			}
			else
			{
				for(int i=0;buffer[i];i++)
				{
					printf("%c",encode(buffer[i]));
				}
			}
			puts("");
		}
	}
	return 0;
}
