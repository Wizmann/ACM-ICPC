//Result:Apr 25, 2012 7:06:24 PM	Wizmann	 D - Name	 GNU C++	Accepted	 30 ms	 1700 KB
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(X) cin>>x
#define SIZE 5120

char ans[SIZE];
char a[SIZE],b[SIZE];
bitset<SIZE> visit;
int sza,szb;

bool dfs(int pb,int p)
{
	if(pb==sza) return false;
	char *pa=lower_bound(a,a+sza,b[pb]);
	if(pa==a+sza) return false;
	else
	{
		while(*(pa-1)==*pa) pa--;
		while(*pa)
		{
			if(visit[pa-a])
			{
				pa++;
				continue;
			}
			ans[p]=*pa;
			visit[pa-a]=1;
			if(*pa>b[pb])
			{
				for(int i=0;i<sza;i++)
				{
					if(!visit[i])
					{
						ans[++p]=a[i];
					}
				}
				return true;
			}			
			else if(dfs(pb+1,p+1)) return true;
			visit[pa-a]=0;
			ans[p]='\0';
			pa++;
		}
	}
	return false;
}
	
int cmp(const void *a,const void *b)
{
	return *(char*)a-*(char*)b;
}

int main()
{
	freopen("d.txt","r",stdin);
	scanf("%s",a);
	scanf("%s",b);
	sza=strlen(a);
	szb=strlen(b);
	qsort(a,sza,sizeof(char),cmp);
	bool flag=dfs(0,0);
	if(flag) puts(ans);
	else puts("-1");
	return 0;
}

