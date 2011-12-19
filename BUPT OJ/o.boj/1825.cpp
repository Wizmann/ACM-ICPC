#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
	int num;
	int alpha;
	
	void setnum()
	{
		scanf("%d,",&num);
	}
	
	void setalpha()
	{
		scanf("%d,",&alpha);
	}
}tree;

int cmp(const void *a,const void *b)
{
	tree *ta=(tree*)a;
	tree *tb=(tree*)b;
	
	return ta->num-tb->num;	
}

int main()
{
	tree *array=new tree[3];
	
	for(int i=0;i<3;i++) array[i].setnum();
	
	for(int i=0;i<3;i++) array[i].setalpha();
	
	qsort(array,3,sizeof(tree),cmp);
	
	printf("%c",array[0].alpha+'A'-1);
	for(int i=1;i<3;i++) printf(" %c",array[i].alpha+'A'-1);
	printf("\n");
	
	return 0;
}