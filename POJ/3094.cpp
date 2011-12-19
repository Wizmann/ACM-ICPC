#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char temp[300];
    gets(temp);

    while(*temp!='#')
    {
        int len=strlen(temp);
        int sum=0;
        for(int i=0;i<len;i++)
        {
            if(*(temp+i)!=' ') sum+=( *(temp+i)-'A'+1 ) * (i+1);
        }
        printf("%d\n",sum);

        gets(temp);
    }
    return 0;
}
