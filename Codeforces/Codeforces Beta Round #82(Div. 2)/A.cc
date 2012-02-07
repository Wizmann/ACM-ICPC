//Result:Aug 27, 2011 8:44:32 PM 	Wizmann 	A - Card Game 	GNU C++ 	Accepted 	30 ms 	1300 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>

int conv(char p)
{
	if(p>='6'&&p<='9') return p-'0';
	else
	{
		switch(p)
		{
			case 'T':return 10;break;
			case 'J':return 11;break;
			case 'Q':return 12;break;
			case 'K':return 13;break;
			case 'A':return 14;break;
		}
	}
	return -1;
}

int main()
{
	char trump[5];
	char first[5],second[5];
	bool res=false;
	scanf("%s",trump);
	scanf("%s%s",first,second);

	if(first[1]==trump[0]&&second[1]!=trump[0]) res=true;
	else if(first[1]==second[1]&&conv(first[0])>conv(second[0])) res=true;

	if(res) puts("YES");
	else puts("NO");
	return 0;
}

