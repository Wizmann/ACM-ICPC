#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(char ch)
{
    if(ch<'A'||ch>'Z') printf("%c",ch);
    else
    {
        ch-=5;
        if(ch<'A') ch+=26;

        printf("%c",ch);
    }
}

int main()
{

    //freopen("input.txt","r",stdin);

    char string[1000];
    gets(string);
    while(strcmp(string,"ENDOFINPUT")!=0)
    {
        if(strcmp(string,"START")==0); //Do Nothing
        else if(strcmp(string,"END")==0); //Do Nothing
        else
        {
            char *p=string;
            while(*p!='\0') convert(*(p++));
            printf("\n");
        }
        gets(string);
    }
    return 0;
}
