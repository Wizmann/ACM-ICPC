//Result: 2533	Accepted	152K	0MS 	C++	536B	2011-05-02 11:13:27
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <iostream>

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	int input;
	set<int> lis;
	set<int>::iterator iter;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input);
		iter=lis.lower_bound(input);
		if(iter==lis.end()) lis.insert(input);
		else
		{
			lis.erase(iter);
			lis.insert(input);
		}
	}
	
	if(lis.size()==0) printf("1\n");
	else printf("%d\n",lis.size());
	return 0;
}
