//Result:wizmann	3101	Accepted	220K	610MS	C++	2632B
//相对速度：v=(T0-Ti)/(T0Ti)
//ans=(连乘)(LCM(T0Ti)/GCD(T0-T1))/2
//需要大整数
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

#define BASE 10000000000
#define SIZE 500
//#define abs(x) (x>0?x:-x)

class BInt
{
	private:
	long long num[SIZE];
	
	public:
	BInt(){memset(num,0,sizeof(num));}
	BInt(long long x)
	{
		memset(num,0,sizeof(num));
		int pad=0;
		while(x>0)
		{
			num[pad++]=x%BASE;
			x/=BASE;
		}
	}
	BInt(char *s)
	{
		int pad=0;
		for(int i=0;s[i];i++)
		{
			if(num[pad]>BASE)
			{
				int t=num[pad]/BASE;
				num[++pad]=t;
			}
			else num[pad]=num[pad]*10+(s[i]-'0');
		}
	}
	
	friend BInt operator + (BInt a,BInt b)
	{
		long long g=0;
		for(int i=0;i<SIZE;i++)
		{
			a.num[i]=g+a.num[i]+b.num[i];
			g=a.num[i]/BASE;
		}
		return a;
	}
	
	friend BInt operator * (BInt a,long long b)
	{
		long long g=0;
		for(int i=0;i<SIZE;i++)
		{
			a.num[i]=a.num[i]*b+g;
			g=a.num[i]/BASE;
			a.num[i]%=BASE;
		}
		return a;	
	}
	
	friend BInt operator / (BInt a,const long long b)
	{
		long long g=0;
		for(int i=SIZE-1;i>=0;i--)
		{
			a.num[i]+=g*BASE;
			g=a.num[i]%b;
			a.num[i]/=b;
		}
		return a;
	}
	
	friend long long operator % (BInt a,long long b)
	{
		long long g=0;
		for(int i=SIZE-1;i>=0;i--)
		{
			a.num[i]+=g*BASE;
			g=a.num[i]%b;
		}
		return g;
	}
	
	void print()
	{
		int i=SIZE-1;
		while(!num[i]) i--;
		printf("%lld",num[i--]);
		while(i>=0) printf("%010lld",num[i--]);
	}
};

long long gcd(long long a,long long b)
{
	if(a<b) return gcd(b,a);
	if(b==1) return 1;
	
	long long c=a%b;
	if(!c) return b;
	else return gcd(b,c);
}

long long gcd(BInt a,long long b)
{
	long long mod=a%b;
	if(mod==0) return b;
	else return gcd(b,mod);
}

BInt lcm(BInt a,long long b)
{
	long long t=gcd(a,b);
	a=a*b;
	return a/t;
}

long long lcm(long long a,long long b)
{
	return (a*b)/gcd(a,b);
}

bool cmp(int a,int b)
{
    return a>b;
}
long long in[1010];
long long f[1010],s[1010];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",in+i);
	std::sort(in,in+n,cmp);
	int pad=1;
	for(int i=1;i<n;i++)
	{
		if(in[i]!=in[i-1]&&in[i])
		{
			f[pad]=in[0]*in[i];
			s[pad]=in[0]-in[i];
			long long t=gcd(f[pad],s[pad]);
			f[pad]/=t;s[pad]/=t;
			pad++;
		}
	}
	BInt father(f[1]);
	for(int i=2;i<n;i++)
	{
		if(f[i]) father=lcm(father,f[i]);
	}
	long long son(s[1]);
	for(int i=2;i<n;i++)
	{
		if(s[i]) son=gcd(son,s[i]);
	}
	son*=2;
	long long t=gcd(father,son);
	father=father/t;
	son/=t;
	father.print();
	printf(" %lld\n",son);
	return 0;
}
