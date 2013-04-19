//Result:	1867	2013-04-19 18:47:05	Accepted	0.48 s	9196 K	C++	1768 B	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 1024000;

inline int lowbit(int x){return x&(-x);}

struct BIT
{
	int array[SIZE];

	inline void init()
	{
		memset(array,0,sizeof(array));
	}

	inline void add(int x,int val)
	{
		while(x<SIZE)
		{
			array[x]+=val;
			x+=lowbit(x);
		}
	}

	inline int sum(int x)
	{
		int val = 0;
		while(x>0)
		{
			val += array[x];
			x -= lowbit(x);
		}
		return val;
	}

	inline int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

bool isPrime(int x)
{
	if(x < 2) return false;
	else if(x == 2) return true;
	else if(!(x%2)) return false;
	else
	{
		int flag = sqrt(x) + 1;
		for(int i=3;i<=flag;i+=2)
		{
			if(!(x%i)) return false;
		}
		return true;
	}
}

int box[SIZE];
int c,n,m;

int main()
{
	BIT bit;
	int a,b,c,cas=1;
	while(input(c>>n>>m) && c+n+m)
	{
		printf("CASE #%d:\n",cas++);
		bit.init();
		int flag = isPrime(m)? 1 : 0;
		for(int i=1;i<=c;i++)
		{
			box[i]=m;
			bit.add(i,flag);
		}
		while(n--)
		{
			input(a>>b>>c);
			if(a == 0)
			{
				bool isPrimeBefore = isPrime(box[b]);
				box[b]+=c;
				bool isPrimeAfter  = isPrime(box[b]);
				if(isPrimeBefore == isPrimeAfter) flag =0;
				else if(isPrimeBefore && !isPrimeAfter) flag = -1;
				else if(!isPrimeBefore && isPrimeAfter) flag = 1;
				else{ while(1){} }//make it TLE
				bit.add(b,flag);
			}
			else
			{
				print(bit.sum(b,c));
			}
		}
		puts("");
	}
	return 0;
}





