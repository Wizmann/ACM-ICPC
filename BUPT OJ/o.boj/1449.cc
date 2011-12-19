#include <cstdio>
#include <set>

using namespace std;

int main()
{
	set<int> array;
	set<int>::iterator iter;
	
	array.insert(1);
	iter=array.begin();
	for(int i=0;i<10100;i++)
	{
		array.insert(*iter*2+1);
		array.insert(*iter*3+1);
		iter++;
	}
	
	iter=array.begin();
	int k;
	scanf("%d",&k);
	while(--k) iter++;
	printf("%d\n",*iter);
	return 0;
}