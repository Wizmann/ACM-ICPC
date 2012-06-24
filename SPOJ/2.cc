//Result:2012-06-24 07:54:56	Moody Wizmann	Prime Generator	 accepted 	1.70	 2.6M 	C++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

typedef long long llint;

class Miller_Rabin
{
public:
	Miller_Rabin(int i_test_time=3)
	{
		test_time=i_test_time;
		srand(time(NULL));  
		for(int i=0;i<SIZE;i++) random_list[i]=rand();
		ptr=0;
	}
	int test_time,ptr;
	enum{SIZE=100};
	int random_list[SIZE];
	
private:
	llint random(llint m,llint n)  
	{  
		ptr%=SIZE;
		return random_list[ptr++]%(n-m)+m;
		
	}
	
	llint FastMod(llint a,llint n,llint b)
	{
		llint t;
		if(n==0) return 1;
		if(n==1) return a%b;
		t=FastMod(a,n>>1,b);
		t=t*t%b;
		if(n&1) t=t*a%b;
		return t;
	}
	
	bool mr_test(llint n)  
	{  
		llint b,m,j,v;
		m=n-1;
		j=0;
		while(!(m&1))  
		{
			++j;  
			m>>=1;
		}
		b=random(2,m);
		v=FastMod(b,m,n);
		if(v==1) return true;
		int i=1;  
		while(v!=n-1)
		{
			if(i==j) return false;
			v=FastMod(v,2,n);  
			i++;  
		}  
		return true;  
	}
public:
	bool judge(llint x)
	{
		//print(x);
		if(x<2) return false;
		if(x==2) return true;
		for(int i=0;i<test_time;i++)
		{
			if(!mr_test(x)) return false;
		}
		return true;
	}
};


int main()
{
	Miller_Rabin mr(3);
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)
		{
			if(i!=2 && !(i&1)) continue;
			if(mr.judge(i)) printf("%d\n",i);
		}
		puts("");
	}
	return 0;
}
	
  
	
