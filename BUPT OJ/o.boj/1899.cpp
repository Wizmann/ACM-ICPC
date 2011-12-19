#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct name
{
	int len;
	int asc;
	char str[150];

	name()
	{
		len=0;
		asc=0;
		memset(str,0,sizeof(str));
	}

	void setname()
	{
		char *p=str;
		scanf("%s",str);
		len=strlen(str);
		while(*p!='\0')
		{
			asc+=*p;
			p++;
		}
	}

}name;

int cmp(const void *a,const void *b)
{
	name *ta,*tb;
	ta=(name*)a;
	tb=(name*)b;

	if(ta->len>tb->len) return -1;
	else
	{
		if(ta->len==tb->len)
		{
			if(ta->asc>tb->asc) return -1;
			else return 1;
		}
		else return 1;
	}
}

int main()
{

	freopen("input.txt","r",stdin);

	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		int num;
		scanf("%d",&num);
		name *array=new name[num];
		for(int i=0;i<num;i++)
		{
			array[i].setname();
		}
		qsort(array,num,sizeof(name),cmp);

		if(array[0].len>array[1].len) printf("%s\n",array[0].str);
		else
		{
			if(array[0].asc>array[1].asc) printf("%s\n",array[0].str);
			else printf("@_@\n");
		}
		delete [] array;
	}
	return 0;
}
