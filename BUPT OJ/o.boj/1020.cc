#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Case 1:
SSSSD SSSSD SS
Case 2:
SSSDD SSSDD SS
Case 3:
SSDDD SSDDD SS
Case 4:
SDDDD SDDDD SD
Case 5:
DDDDD DDDDD DD
*/

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int surplus,deficit;
	while(scanf("%d%d",&surplus,&deficit)==2)
	{
		int res;
		if(4*surplus-deficit<0) res=10*surplus-2*deficit;
		else if(3*surplus-2*deficit<0) res=8*surplus-4*deficit;
		else if(2*surplus-3*deficit<0) res=6*surplus-6*deficit;
		else if(surplus-4*deficit<0) res=3*surplus-9*deficit;
		else res=-12*deficit;
		
		if(res<0) printf("Deficit\n");
		else printf("%d\n",res);
	}
	return 0;
}