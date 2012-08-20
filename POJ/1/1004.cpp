#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 12

int main()
{
    freopen("input.txt","r",stdin);

    float sum=0;
    float input;
    for(int i=0;i<N;i++)
    {
        scanf("%f",&input);
        sum+=input;
    }
    printf("$%.2f\n",sum/N);
    return 0;
}
