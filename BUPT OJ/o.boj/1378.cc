#include <cstdio>
#include <cstring>

int bitset[100];
int *p;

inline void push(int n)
{
	*p^=n;
	p++;
}

inline void init()
{
	p=bitset;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char input[15];
	char *ch;
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(bitset,0,sizeof(bitset));
		for(int f=0;f<2*n-1;f++)
		{
			scanf("%s",input);
			ch=input;
			init();
			while(*ch!='\0')
			{
				for(int i=0;i<8;i++)
				{
					push(*ch%2);
					*ch/=2;
				}
				ch++;
			}
		}
		memset(input,0,sizeof(input));
		int *t=bitset;
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<8;j++)
			{
				input[i]+=*t<<j;
				t++;
			}
		}
		
		puts(input);
	}
	return 0;
}
		
