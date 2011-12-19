#include <stdio.h>
#include <string.h>

int wood[10];

int main()
{
	char temp[10];
	memset(wood,0,sizeof(wood));
	scanf("%s",temp);
	while(strlen(temp)!=1||temp[0]!='0')
	{
		char *p=temp;
		while(*p!='\0')
		{
			wood[*p-'0']++;
			p++;
		}
	 	wood[6]+=wood[9];
        wood[9]=0;
        wood[6]=(wood[6]%2)+(wood[6])/2;
        int max=0;
        for(int i=0;i<9;i++) if(wood[i]>max) max=wood[i];
        printf("%d\n",max);
        memset(temp,0,sizeof(temp));
        memset(wood,0,sizeof(wood));
        scanf("%s",temp);
	}
	return 0;
}
