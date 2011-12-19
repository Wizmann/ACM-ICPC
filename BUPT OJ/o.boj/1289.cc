#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int score[210];
int total;

typedef struct stu
{
    char name[25];
    char nr[9];
    double ave;
    
    void setstu(int n)
    {
        scanf("%s%s",name,nr);
        int temp;
        ave=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            ave+=temp*score[i];
        }
        ave/=total;
    }
    
    void print()
    {
        printf("%s ",name);
        printf("%s ",nr);
        printf("%.2lf\n",ave);
    }
}stu;

stu array[210];


int cmp(const void *a,const void *b)
{
    stu *ta=(stu*)a;
    stu *tb=(stu*)b;
    
    if(tb->ave>ta->ave) return 1;
    else return 0;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
    int cas;
    scanf("%d",&cas);
    for(int i=1;i<=cas;i++)
    {
        int sub;
        total=0;
        scanf("%d",&sub);
        for(int j=0;j<sub;j++)
        {
				scanf("%d",&score[j]);
				total+=score[j];
		}
        
        int people;
        scanf("%d",&people);
        memset(array,0,sizeof(array));
        for(int j=0;j<people;j++) array[j].setstu(sub);
        
        qsort(array,people,sizeof(stu),cmp);
        
        printf("Case #%d:\n",i);
        for(int j=0;j<people;j++) array[j].print();
    }
    return 0;
}
            
