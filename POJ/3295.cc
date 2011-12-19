//Result: Wizmann 3295	Accepted	180K	0MS	C++	 894B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>

using namespace std;
char str[120];
bitset<5> bs;
int p;

bool val()
{
	char ch=str[p++];
	if(ch>='p'&&ch<='t') return bs[ch-'p'];
	else
	{
		switch(ch)
		{
			case 'K': return val()&val();break;
			case 'A': return val()|val();break;
			case 'N': return !val();break;
			case 'C': return !val()|val();break;
			case 'E': return val()==val();break;
			default: return -1;break;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(1)
	{
		scanf("%s",str);
		int len=strlen(str);
		if(len==1&&*str=='0') break;
		int mark=1;
		for(int i=0;i<=31;i++)
		{
			int t=i;
			bs.reset();
			for(int j=0;t>0;j++)
			{
				if(t%2) bs.set(j);
				t/=2;
			}
			
			p=0;
			if(val()==0)
			{
				mark=0;
				break;
			}
		}

		if(mark) puts("tautology");
		else puts("not");
	}
	return 0;
}
		
