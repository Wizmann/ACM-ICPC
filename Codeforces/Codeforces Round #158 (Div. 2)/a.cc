//Result:2882177	 Jan 8, 2013 11:12:49 AM	Wizmann	 A - Adding Digits	 GNU C++	Accepted	15 ms	104 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100

char num[SIZE];

bool slove(int a,int b,int n)
{
	memset(num,0,sizeof(num));
	sprintf(num,"%d",a);
	int ptr=strlen(num);
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=0;j<=9;j++)
		{
			int t=a*10+j;
			if(t%b==0)
			{
				num[ptr++]=j+'0';
				flag=true;
				a=(a*10+j)%b;
				break;
			}
		}
		if(!flag) return false;
	}
	print(num);
	return true;
}

int main()
{
	freopen("a.txt","r",stdin);
	int a,b,n;
	while(input(a>>b>>n))
	{
		if(!slove(a,b,n)) print(-1);
	}
	return 0;
}

