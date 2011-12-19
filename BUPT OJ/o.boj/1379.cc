#include <cstdio>
#include <cstdlib>
#include <cstring>

long long num[700000];

int main()
{
	char g=-1;
	while(1)
	{
		g=getchar();
		if(g<=0) break;
		while(g==' '||g=='\n'||g=='0') g=getchar();
		int pad=0,t=0;
		while(g!='\n')
		{
			num[pad]*=10;
			num[pad]+=g-'0';
			t++;
			if(t==13) t=0;pad++;
		}
		if(num[pad]==0&&g!='0') pad--;
