#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	float all;
	scanf("%f",&all);
	int zero,eins,zwei,drei,tot;
	scanf("%d,%d,%d,%d",&zero,&eins,&zwei,&drei);
	tot=zero+eins+zwei+drei;
	eins+=zero;
	zwei+=zero;
	printf("%.3f,%.3f\n",(float)eins/tot,(float)zwei/tot);
	if(all<0.7) printf("No passed.\n");
	else
	{
		if((float)zwei/tot>(float)2/3&&(float)eins/tot>(float)2/3) printf("1,2\n");
		else
		{
			if((float)eins/tot>(float)2/3) printf("1\n");
			else if((float)zwei/tot>(float)2/3) printf("2\n");
			else printf("No passed.\n");
		}
	}
	return 0;
}
