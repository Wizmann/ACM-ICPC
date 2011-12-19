#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[655360];

int main()
{
    freopen("input.txt","r",stdin);    
        
    char input[50];
    memset(input,0,sizeof(input));
    char *p;
    while(scanf("%s",input)!=EOF)
    {
        strcat(string,input);
    }
    
    p=string;
    int H=0,O=0;
    while(*p!='E')
    {
        if(*p=='W') H++;
        else if(*p=='L') O++;
        if( (O>=11||H>=11)&&abs(H-O)>=2 )
        {
            printf("%d:%d\n",H,O);
            H=0;O=0;
        }
        p++;
    }
    printf("%d:%d\n\n",H,O);
    
    H=0;O=0;
    p=string;
    while(*p!='E')
    {
        if(*p=='W') H++;
        else if(*p=='L') O++;
        if( (O>=21||H>=21)&&abs(H-O)>=2 )
        {
            printf("%d:%d\n",H,O);
            H=0;O=0;
        }
        p++;
    }
    printf("%d:%d\n",H,O);
    
    return 0;
}
