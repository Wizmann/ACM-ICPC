#include <cstdio>
#include <algorithm>
#include <set>

#define N 50010

using namespace std;

int a[N];
int b[N];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	
	set<int> out;
	set<int>::iterator iter;
	
	int i=0,j=0;
	while(i<n&&j<n)
	{
		if(a[i]>b[j]) j++;
		else if(a[i]==b[j])
		{
			out.insert(a[i]);
			i++;j++;
		}
		else i++;
	}
	
	iter=out.begin();
	printf("%d",out.size());
	while(iter!=out.end())
	{
		printf(" %d",*iter);
		iter++;
	}
	printf("\n");
	return 0;
}