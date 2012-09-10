//Result:2012-09-10 11:10:20	Accepted	4278	0MS	488K	558 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20

char num[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	while(scanf("%s",num)!=EOF)
	{
		if(!strcmp(num,"0")) break;
		
		printf("%s: ",num);
		for(int i=0;num[i];i++)
		{
			if(num[i]-'0'>3 && num[i]-'0'<8)
			{
				num[i]=num[i]-1;
			}
			else if(num[i]-'0'>8) num[i]-=2;
		}
		sscanf(num,"%o",&t);
		print(t);
	}
	return 0;
}
