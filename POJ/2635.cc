#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <iostream>

using namespace std;

long long num[100];
char word[250];
long long l;
bitset<1000010> prim;
int pad;

void init()
{
	for(int i=2;i<=1020;i++)
	{
		if(!prim[i])
		{
			for(int j=2;i*j<1000010;j++) prim[i*j]=1;
		}
	}
}

bool mod(long long n)
{
	long long t=0;
	for(long long i=pad;i>=0;i--)
	{
		t=num[i]+t*100000;
		t%=n;
	}
	if(t%n==0) return true;
	else return false;
}		

int main()
{
	init();
	while(1)
	{
		pad=0;
		memset(num,0,sizeof(num));
		scanf("%s%lld",word,&l);
		int len=strlen(word);
		if(len==1&&*word=='0'&&l==0) break;
		len--;
		while(len>=0)
		{
			int mul=1;
			for(int i=0;i<5;i++)
			{
				if(len<0) break;
				num[pad]=num[pad]+mul*(word[len]-'0');
				len--;
				mul*=10;
			}
			pad++;
		}
		pad--;
		bool ok=false;
		for(long long i=2;i<l;i++)
		{
			if(!prim[i]&&mod(i))
			{
				printf("BAD %lld\n",i);
				ok=true;
				break;
			}
		}
		if(!ok) printf("GOOD\n");
	}
	return 0;
}
