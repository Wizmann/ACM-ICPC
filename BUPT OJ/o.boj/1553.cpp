#include <stdio.h>
#include <string.h>

int main()
{
	freopen("input.txt","r",stdin);
	double sum=0;
	char print[500]="";
	char pt[10]="";
	int n;
	scanf("%d",&n);
	double suma=0,sumb=0;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(n%2==0)
		{
			if(i<(int)n/2) suma+=(double)temp;
			if(i>=(int)n/2) sumb+=(double)temp;
		}
		else
		{
			if(i<(int)n/2) suma+=(double)temp;
			if(i>(int)n/2) sumb+=(double)temp;
		}
	
		sum+=(double)temp;
		scanf(",");
	}	
	printf("%.3lf,%.3lf,%.3lf\n",sum/n,suma/(n/2),sumb/(n/2));
	return 0;
}