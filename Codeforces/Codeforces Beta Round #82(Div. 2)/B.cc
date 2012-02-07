//Result:Aug 27, 2011 9:16:20 PM 	Wizmann 	B - Choosing Laptop 	GNU C++ 	Accepted 	30 ms 	1300 KB 
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct node
{
	int price;
	int val[5];
	bool avi;

	inline void setnode()
	{
		for(int i=0;i<3;i++) scanf("%d",val+i);
		scanf("%d",&price);
		avi=true;
	}

	friend bool operator < (const node a,const node b)
	{
		int t=0;
		for(int i=0;i<3;i++)
		{
			if(a.val[i]<b.val[i]) t++;
		}
		if(t==3) return true;
		else return false;
	}
}node;

node array[105];
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++) array[i].setnode();

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) if(i!=j)
		{
			if(array[i]<array[j]) array[i].avi=false;
		}
	}
	int pos=-1,value=1<<20;
	for(int i=0;i<n;i++)
	{
		if(array[i].avi&&array[i].price<value)
		{
			pos=i;value=array[i].price;
		}
	}
	printf("%d\n",pos+1);
	return 0;
}
