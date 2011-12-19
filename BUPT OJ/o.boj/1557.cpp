#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int numo=0,nume=0;
	int sodd=0,seven=0;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp%2==0)
		{
			seven+=temp;
			nume++;
		}
		else
		{
			sodd+=temp;
			numo++;
		}
	}
	if(numo!=0) printf("%.3f ",(float)sodd/numo);
	if(nume!=0) printf("%.3f\n",(float)seven/nume);
	return 0;
}