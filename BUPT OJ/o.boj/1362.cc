#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

typedef struct pep
{
	int nr,p;
	
	void setpep()
	{
		scanf("%d%d",&nr,&p);
	}
	
	friend bool operator < (const pep& a,const pep& b)
	{
		return a.p<b.p;
	}
}pep;

set<pep> m;
set<pep>::iterator iter;

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	pep temp;
	while(scanf("%d",&n),n)
	{
		if(n==1)
		{
			temp.setpep();
			m.insert(temp);
		}
		else if(n==2)
		{
			if(m.empty()) printf("0\n");
			else
			{
				iter=m.end();
				iter--;
				printf("%d\n",(*iter).nr);
				m.erase(iter);
			}
		}
		else if(n==3)
		{
			if(m.empty()) printf("0\n");
			else
			{
				iter=m.begin();
				printf("%d\n",(*iter).nr);
				m.erase(iter);
			}
		}
	}
	return 0;
}
