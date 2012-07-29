//Result:2012-07-29 20:44:10	 Accepted	3622	C++	0	576	Wizmann
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

const long long MAX=1LL<<31;
#define SIZE 50000

typedef long long llint;

llint vec[SIZE];
int ind;

int main()
{
	ind=1;
	for(llint i=10;i<=MAX*10;i*=10)
	{
		for(llint j=1;j<10;j++)
		{
			if(i%j==0) vec[ind++]=i/j;
			
		}
	}
	vec[ind++]=1;
	sort(vec+1,vec+ind);
	
	int a,b;
	
	while(input(a>>b))
	{
		int ta=lower_bound(vec,vec+ind,a)-vec-1;
		int tb=upper_bound(vec,vec+ind,b)-vec-1;
		
		print(tb-ta);
	}
	return 0;
}
