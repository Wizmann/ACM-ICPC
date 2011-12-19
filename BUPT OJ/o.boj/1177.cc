#include <cstdio>
#include <cstring>
#include <cstdlib>

short array[10010];
int num[4];
int a,b,c,d;

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%hd",&array[i]);
		num[array[i]]++;
	}
	
	for(int i=0;i<num[1];i++)
	{
		if(array[i]==2) a++;
		else if(array[i]==3) b++;
	}
	
	for(int i=num[1];i<num[2]+num[1];i++)
	{
		if(array[i]==1) c++;
		else if(array[i]==3) d++;
	}

	if(a>c) printf("%d\n",a+b+d);
	else printf("%d\n",b+c+d);
	
	return 0;
}
