#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char balance[20];

int abs(int x)
{
	return x>0?x:-x;
}	

int main()
{

	freopen("input.txt","r",stdin);

    int counter;
    scanf("%d",&counter);
    while(counter--)
    {
        memset(balance,0,sizeof(balance));
        char left[13],right[13],cmd[13];
        for(int i=0;i<3;i++)
        {
            scanf("%s%s%s",left,right,cmd);
            if(*cmd=='e')
            {
                char *p=left;
                while(*p!='\0') balance[*p++-'A']=100;
                p=right;
                while(*p!='\0') balance[*p++-'A']=100;
            }
            else if(*cmd=='u')
            {
                char *p=left;
                while(*p!='\0')
                {
                    if(balance[*p-'A']!=100) balance[*p-'A']++;
                    p++;
                }
                p=right;
                while(*p!='\0')
                {
                    if(balance[*p-'A']!=100) balance[*p-'A']--;
                    p++;
                }
            }
            else if(*cmd=='d')
            {
                char *p=left;
                while(*p!='\0')
                {
                    if(balance[*p-'A']!=100) balance[*p-'A']--;
                    p++;
                }
                p=right;
                while(*p!='\0')
                {
                    if(balance[*p-'A']!=100) balance[*p-'A']++;
                    p++;
                }
            }
        }
        
        int max=-1<<20,id=0;
        for(int i=0;i<12;i++)
        {
           if(balance[i]!=100&&abs(balance[i])>max)
           {
			   max=abs(balance[i]);
			   id=i;
		   }
        }
        printf("%c is the counterfeit coin and it is ",id+'A');
        if(balance[id]>0) puts("heavy.");
        else puts("light.");
    }
    return 0;
}
