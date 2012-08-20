//Result:wizmann	3276	Accepted	264K	344MS	C++	855B	

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 5010

int n;
char pos[SIZE];
char head[SIZE];

int main()
{
	char ch[3];
	input(n);
	head[0]=1;
	for(int i=1;i<=n;i++)
	{
		input(ch);
		if(*ch=='B') head[i]=0;
		else head[i]=1;

		if(head[i]==head[i-1]) pos[i]=1;
		else pos[i]=0;
	}

	int m=1<<25,k=0,sum;
	char tmp[SIZE];
	for(int i=1;i<=n;i++)
	{
		sum=0;
		memcpy(tmp,pos,sizeof(pos));
		for(int j=1;j<=n-i+1;j++)
		{
			if(!tmp[j])
			{
				tmp[j]=1;
				tmp[j+i]^=1;
				sum++;
			}
		}
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(!tmp[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			m=min(m,sum);
			k=i;
		}
	}
	print(k<<' '<<m);
	return 0;
}
