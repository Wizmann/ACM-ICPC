#include <stdio.h>
#include <rope.h>

int att[15];
int main()
{
	
	freopen("input.txt","r",stdin);
	
	int a,b,input;
	
	scanf("%d%d",&a,&b);
	while(a&&b)
	{
		int def=1<<30;
		while(a--)
		{
			scanf("%d",&input);
			if(def>input) def=input;
		}
		for(int i=0;i<b;i++) scanf("%d",att+i);
		nth_element(att,att+1,att+b);
		
		if(att[1]>def) printf("Y\n");
		else printf("N\n");
		
		scanf("%d%d",&a,&b);
	}
	return 0;
}
