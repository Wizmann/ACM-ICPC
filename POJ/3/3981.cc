//Result:wizmann	3981	Accepted	688K	0MS	G++	466B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

char str[1024];

int main()
{
	while(gets(str))
	{
		char *p=str;
		p=strtok(str," ");
		while(p)
		{
			if(strcmp(p,"you")==0)
			{
				printf("we");
			}
			else printf("%s",p);
			p=strtok(NULL," ");
			if(p) printf(" ");
		}
		puts("");
	}
	return 0;
}
