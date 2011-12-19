#include <cstdio>
#include <rope.h>

using namespace std;

int cup[5000010];

int main()
{
	freopen("input.txt","r",stdin);
	
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;i++) scanf("%d",&cup[i]);
		nth_element(cup,cup+k-1,cup+n);
		printf("%d\n",cup[k-1]);
	}

	return 0;
}
