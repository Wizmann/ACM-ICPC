#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len;

typedef struct DNA
{
    char str[55];
    int sort;
    int nr;

    DNA()
    {
        memset(str,0,sizeof(str));
        sort=0;
        nr=-1;
    }

    void getDNA(int n)
    {
        scanf("%s",str);
        nr=n;
    }

    void getsort()
    {
        char *p=str;
        while(p<str+len-1)
        {
            for(int i=1;*(p+i)!='\0';i++) if(*(p+i)<*p) sort++;
            p++;
        }
    }
    void print()
    {
        puts(str);
        //printf("%d\n",sort);
    }
}dna;

int cmp(const void *a,const void *b)
{
    dna *ta=(dna*)a;
    dna *tb=(dna*)b;

    if(ta->sort>tb->sort) return 1;
    else if(ta->sort<tb->sort) return -1;
    else if(ta->nr>tb->nr) return 1;
    else return -1;
}

int main()
{
    int n;
    while(scanf("%d%d",&len,&n)!=EOF)
    {
        dna *array=new dna[n];
        for(int i=0;i<n;i++)
        {
            array[i].getDNA(i);
            array[i].getsort();
        }

        qsort(array,n,sizeof(dna),cmp);

        for(int i=0;i<n;i++) array[i].print();
        delete [] array;
    }
    return 0;
}

