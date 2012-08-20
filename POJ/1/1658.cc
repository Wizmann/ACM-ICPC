#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    int array[4];

    scanf("%d",&n);
    while(n--)
    {
        for(int i=0;i<4;i++) scanf("%d",&array[i]);

        int flag=1;
        for(int i=0;i<2;i++)
        {
            if(array[i]-array[i+1]==array[i+1]-array[i+2]); //Do Nothing
            else
            {
                flag=0;
                break;
            }
        }

        for(int i=0;i<4;i++) printf("%d ",array[i]);

        if(flag==1)
        {
            printf("%d\n",array[3]+array[3]-array[2]);
        }
        else
        {
            printf("%d\n",array[3]*(array[3]/array[2]));
        }
    }
    return 0;
}
