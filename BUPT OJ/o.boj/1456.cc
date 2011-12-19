#include <cstdio>
#include <iostream>

using namespace std;

#define N 20000+100
#define START 0
#define left(x) ((x<<1)+1)
#define right(x) (left(x)+1)
#define parent(x) ((x-1)>>1)


long long heap[N];
int size=0;

void up(int pos)
{
	for(int i=pos;i>0;i=parent(i))
	{
		if(heap[i]<heap[parent(i)]) swap(heap[i],heap[parent(i)]);
		else break;
	}
}

void down(int pos)
{
	while(left(pos)<size)
	{
		int j=left(pos);
		if(heap[left(pos)]>heap[right(pos)]) j=right(pos);
		
		if(heap[pos]>heap[j]) swap(heap[pos],heap[j]);
		else break;
		pos=j;
	}
}

void push(int n)
{
	heap[size]=n;
	up(size);
	size++;
}

long long pop()
{
	long long res=heap[START];
	size--;
	heap[START]=heap[size];
	
	down(START);
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int n,temp;	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&temp);
		push(temp);
	}
	
	long long sum=0;
	long long a,b;
	while(size!=1)
	{
		a=pop();
		b=pop();
		sum+=(a+b);
		push(a+b);
	}
	printf("%lld\n",sum);
	return 0;
}
