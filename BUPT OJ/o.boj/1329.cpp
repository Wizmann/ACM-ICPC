#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{    
    int cas=1;
    int n;
    while(scanf("%d",&n)!=-1)
    {
        int *array=new int[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&array[i]);
        }
        qsort(array,n,sizeof(int),cmp);
        printf("Case %d: %d\n\n",cas++,array[n/2]);
        delete [] array;

    }
    return 0;
}
