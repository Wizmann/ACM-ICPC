#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

priority_queue <int> now,want;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,add,red;
	int a,b;
	scanf("%d%d%d",&n,&add,&red);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		now.push(a);
		want.push(b);
	}
	
	int sum=0;
	int t;
	for(int i=0;i<n;i++)
	{
		a=now.top();
		b=want.top();
		t=a-b;
		if(t>0) sum+=red*t;
		else sum+=add*(-t);
		
		now.pop();
		want.pop();
	}
	
	printf("%d\n",sum);
	return 0;
}
		
