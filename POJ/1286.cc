//Result:wizmann	1286	Accepted	728K	0MS	G++	1051B	
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define llint long long

llint n,m=3;

llint gcd(llint a,llint b)
{
	return b==0?a:gcd(b,a%b);
}

llint pow(llint a,llint b)
{
	if(!b) return 1;
	llint t=pow(a,b>>1);
	if(b&1) return t*t*a;
	else return t*t;
}


int main()
{
	while(input(n)&&n>=0)
	{
		if(n==0)
		{
			print(0);
			continue;
		}
		llint ans=0;
		for(int i=0;i<n;i++) ans+=pow(m,gcd(n,i));
		/*
		 * 顺时针旋转i格的转换中，循环的个数为gcd(n,i)，每个循环的长度为n/gcd(n,i)
		 */
		if(n&1) ans+=n*pow(m,n/2+1);
		else ans+=n/2*( pow(m,n/2)+pow(m,n/2+1) );
		/*
		 * 当n为奇数时，有[n/2]个循环长度为2，还有一个长度为1
		 * 所以 ans+= {颜色数m}^[n/2+1]*{节点数n}
		 * 
		 * 当n为偶数时，两种情况
		 * a.[n/2]长度为2的循环
		 * b.[n/2-1]长度为2的循环，2个长度为1的循环
		 * 所以 ans+= ( {颜色数m}^[n/2]*{节点数n} + {颜色数m}^[n/2]*{节点数n} ) /2
		 */
        print(ans/2/n);
        // |G|=2*n 所以ans/=2*n
    }
    return 0;
} 
