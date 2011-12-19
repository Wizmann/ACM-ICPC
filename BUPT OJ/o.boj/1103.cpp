#include <stdio.h>
#include <stdlib.h>


int comp(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;
}

int *creat(int n)
{
    int *ret=(int*)malloc(sizeof(int)*n);
    return ret;
}

int main()
{
    int n;
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Scenario #%d:\n",i+1);
        int need,people;
        scanf("%d%d",&need,&people);
        int *queue=creat(people);
        for(int j=0;j<people;j++) scanf("%d",&queue[j]);
        qsort(queue,people,sizeof(int),comp);
        int sum=0;
        int man=0;
        for(int j=0;j<people;j++)
        {
            sum+=queue[j];
            man++;
            if(sum>=need) break;
        }
        if(sum>=need) printf("%d\n\n",man);
        else printf("impossible\n\n");
        free(queue);
    }
    return 0;
}
