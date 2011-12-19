#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

int array[50010];
set<int> sum;
int t=1;

void init(int n)
{
	for(int i=1;i<=n;i++) array[i]=i;
}

int find(int n)
{
	if(array[n]==n) return n;
	else return array[n]=find(array[n]);
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int point,ask;
	while(scanf("%d%d",&point,&ask)!=EOF&&point&&ask)
	{
		init(point);
		int a,b;
		while(ask--)
		{
			scanf("%d%d",&a,&b);
			array[find(a)]=find(b);
		}
		
		sum.clear();
		for(int i=1;i<=point;i++)
		{
			//printf("%d\n",find(i));
			sum.insert(find(i));
		}
		
		printf("Case %d: %d\n",t++,sum.size());
	}
	return 0;
}
		
			
