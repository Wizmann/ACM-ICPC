#include <cstdio>
#include <set>

using namespace std;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		multiset<int> cmi;
		multiset<int>::iterator iter;
		int temp;
		scanf("%d",&temp);
		cmi.insert(temp);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&temp);
			iter=cmi.end();
			iter--;
			if(temp>*iter) cmi.insert(temp);
			else if(temp==*iter) ;
			else
			{
				iter=cmi.lower_bound(temp);
				/*lower_bound() 返回指向大于（或等于）某值的第一个元素的迭代器*/
				if(iter!=cmi.end())
				{
					cmi.erase(iter);
					cmi.insert(temp);
				}
			}
		}
		
		printf("%d\n",cmi.size());
		cmi.clear();
	}
	return 0;
}
