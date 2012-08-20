#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int cow[10010];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",cow+i);
	
	nth_element(cow,cow+n/2,cow+n);
	printf("%d\n",cow[n/2]);
	return 0;
}
	
