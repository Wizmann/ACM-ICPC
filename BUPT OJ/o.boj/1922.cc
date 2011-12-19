#include <cstdio>

int main()
{
	char instr[1024];
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%s",instr);
		int gg=0,mm=0;
		for(int i=0;instr[i];i++)
		{
			if(instr[i]=='G') gg++;
			else mm++;
		}
		gg--;

		printf("%dQGG",gg);
		if(gg<=1) printf(" ");
		else printf("s ");
		printf("%dQMM",mm);
		if(mm<=1) printf("\n");
		else printf("s\n");
	}
	return 0;
}

