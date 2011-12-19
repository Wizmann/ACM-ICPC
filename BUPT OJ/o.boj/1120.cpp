#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rev(char *num)
{
    int len=strlen(num);
    char *p=num;
    char *q=num+len-1;
    char temp;
    while(p<q)
    {
        temp=*p;
        *p=*q;
        *q=temp;
        p++;q--;
    }
    p=num;
    while(*p!='\0')
    {
        *p-='0';
        p++;
    }
    return len;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
    int counter;
    scanf("%d",&counter);
    char num[12];
    int len;

    while(counter--)
    {
        memset(num,0,sizeof(num));
        scanf("%s",num);
        len=rev(num);
        int g=0;
        for(int i=0;i<len;i++)
        {
        	num[i]+=g;
            if(num[i]>=5) g=1;
            else g=0;            
        }
        if(num[len]==0)
        {
            printf("%d",num[len-1]);
            for(int i=0;i<len-1;i++) printf("0");
        }
        else
        {
            printf("%d",num[len]);
            for(int i=0;i<len-1;i++) printf("0");
        }
        printf("\n");
    }
    return 0;
}
