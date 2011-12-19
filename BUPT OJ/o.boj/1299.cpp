#include <stdio.h>

int main()
{
	int X=0,Y=0;
	int i=1;
	while(scanf("%d%d",&X,&Y)!=-1)
	{
		printf("Case %d:\n",i);
		char move[1010];
		scanf("%s",move);
		char *p=move;
		while(*p!='\0')
		{
			switch(*p)
			{
				case 'n':Y++;break;
				case 's':Y--;break;
				case 'e':X++;break;
				case 'w':X--;break;
			}
			p++;
		}
		printf("%d %d\n",X,Y);	
		i++;	
	}
	return 0;
}
