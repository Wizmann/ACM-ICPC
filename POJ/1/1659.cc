//Result:wizmann	1659	Accepted	736K	0MS	G++	1168B	2012-09-19 16:11:12
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12

int main()
{
	freopen("input.txt","r",stdin);
	int T,n;
	pair<int,int> array[SIZE];
	int g[SIZE][SIZE];
	input(T);
	while(T--)
	{
		memset(g,0,sizeof(g));
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&(array[i].first));
			array[i].second=i;
		}
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(!flag) break;
			sort(array,array+n,greater<pair<int,int> >());
			if(array[0].first>n-1)
			{
				flag=false;
				break;
			}
			
			for(int j=1;j<=array[0].first;j++)
			{
				array[j].first--;
				if(array[j].first<0)
				{
					flag=false;
					break;
				}
				g[array[0].second][array[j].second]=g[array[j].second][array[0].second]=1;
			}
			array[0].first=0;
		}

		if(flag)
		{
			puts("YES");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(j) printf(" ");
					printf("%d",g[i][j]);
				}
				puts("");
			}
		}
		else puts("NO");
		puts("");
	}
	return 0;
}
