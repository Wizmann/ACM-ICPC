#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>

using namespace std;

typedef struct cmd
{
	char type;
	int num;
}cmd;

cmd array[100100];

bitset<100100> bs;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	
	char str[50];
	bs.set();
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		if(*str=='d') array[i].type='d';
		else
		{
			array[i].type='c';
			scanf("%d",&array[i].num);
		}
	}
	
	for(int i=n-1;i>=0;i--)
	{
		if(bs[i]&&array[i].type=='c') bs.reset(array[i].num-1);
	}
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(bs[i]) ans++;
	}
	printf("%d\n",ans);
	
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		if(!flag&&bs[i]) printf(" %d",i+1);
		else if(flag&&bs[i])
		{
			printf("%d",i+1);
			flag=false;
		}
	}
	printf("\n");
	
	return 0;
}
		
		
	
