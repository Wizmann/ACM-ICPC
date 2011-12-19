#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 26

int alpha[N];

int main()
{

    freopen("input.txt","r",stdin);

    char ch;
    while(scanf("%c",&ch)!=EOF)
    {
        if(ch>='A'&&ch<='Z') alpha[ch-'A']++;
    }

    //for(int i=0;i<N;i++) printf("%d ",alpha[i]);

    int max=-1;
    for(int i=0;i<N;i++)
    {
        if(alpha[i]>max) max=alpha[i];
    }

    for(int i=0;i<max;i++)
    {
        if(alpha[0]>=max-i) printf("*");
        else printf(" ");

        for(int k=1;k<N;k++)
        {
            if(alpha[k]>=max-i) printf(" *");
            else printf("  ");
        }

        printf("\n");
    }

    printf("A");
    for(int i=1;i<N;i++) printf(" %c",'A'+i);
    printf("\n");

    return 0;
}







