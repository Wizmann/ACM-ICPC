//Result:wizmann	1386	Accepted	264K	282MS	C++	1487B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 26
#define LEN 1024

int father[SIZE];
int n;
int in[SIZE],out[SIZE];

void init()
{
	for(int i=0;i<SIZE;i++) father[i]=i;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
}


int find(int x)
{
	if(father[x]==x) return x;
	else return father[x]=find(father[x]);
}

int main()
{
	int T;
	char str[LEN];
	input(T);
	while(T--)
	{
		init();
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			int len=strlen(str);
			int a=str[0]-'a';
			int b=str[len-1]-'a';
			in[a]++;
			out[b]++;
			father[b]=find(a);
		}
		bool flag=true;
		int t=-1;
		for(int i=0;i<SIZE;i++)
		{
			if(in[i]||out[i])
			{
				if(t==-1) t=find(i);
				else if(t!=find(i))
				{
					print("The door cannot be opened.");
					flag=false;
					break;
				}
			}
		}

		if(flag)
		{
			int a,b,c;
			int sum=0;
			a=b=c=0;
			for(int i=0;i<SIZE;i++)
			{
				if(!in[i] && !out[i]) continue;
				sum++;
				if(in[i]-out[i]==1) a++;
				else if(in[i]-out[i]==-1) b++;
				else if(in[i]&&out[i]&&in[i]==out[i]) c++;
			}
			//print(a<<' '<<b<<' '<<c);
			if( (a==1&&b==1 && c==sum-2) || c==sum) print("Ordering is possible.");
			else print("The door cannot be opened.");
		}
	}
	return 0;
}
