#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50050

inline void update(char* buy,int max)
{
    int money;
    scanf("%d",&money);
    for(int i=max;i>=money;i--)
    {
        if(buy[i-money])
        {
            buy[i]=money;
        }
    }
}

int main()
{
	int money,n;
    char buy[N];
    int time;
    scanf("%d",&time);
    for(int runtime=0;runtime<time;runtime++)
    {
        scanf("%d %d",&money,&n);
        memset( buy,0,sizeof(buy) );
        buy[0]=1;
        
        for(int i=0;i<n;i++)
        {
            update(buy,money);
        }
        
        for(int i=money;i>=0;i--)
        {
            if(buy[i]==1)
            {
                printf("%d\n",i);
                break;
            }
        }
    }         
    return 0;
}
