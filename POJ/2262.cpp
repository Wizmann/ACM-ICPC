#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prim(int n)
{
    if(n==1) return 0;
    else if(n<4) return 1;
    else if(n%2==0) return 0;
    else
    {
        for(int i=3;i*i<=n+1;i+=2)
        {
            if(n%i==0) return 0;
        }
        return 1;
    }
}

int main()
{
    int nummer;
    scanf("%d",&nummer);
    while(nummer)
    {
        if(prim(nummer-2)) printf("%d = 2 + %d\n",nummer,nummer-2);
        else
        {
            for(int i=3;i<=nummer/2+1;i+=2)
            {
                if(prim(i)&&prim(nummer-i))
                {
                    printf("%d = %d + %d\n",nummer,i,nummer-i);
                    break;
                }
            }
        }
        scanf("%d",&nummer);
    }
    return 0;
}



