#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct str
{
	char word[25];
	int n;
}str;

str array[1010];

int cmp_word(const void *a,const void *b)
{
	str *ta=(str*)a;
	str *tb=(str*)b;
	return strcmp(ta->word,tb->word);
}

int cmp_nr(const void *a,const void *b)
{
	str *ta=(str*)a;
	str *tb=(str*)b;
	return ta->n-tb->n;
}


int main()
{
	freopen("input.txt","r",stdin);
	
	int nr=0;
	str *ptr=array;
	while(scanf("%s",ptr->word)!=EOF)
	{
		array[nr].n=nr;
		ptr++;
		nr++;
	}
	
	qsort(array,nr,sizeof(str),cmp_word);
	for(int i=0;i<nr;i++)
	{
		int pos=0;
		if(i-1>=0)
		{
			for(/*NULL*/;pos<strlen(array[i].word);pos++)
			{
				if(strncmp(array[i].word,array[i-1].word,pos)!=0) break;
			}
		}
		if(i+1<nr)
		{
			for(;pos<strlen(array[i].word);pos++)
			{
				if(strncmp(array[i].word,array[i+1].word,pos)!=0) break;
			}
		}
		array[i].word[pos]='\0';
	}
	
	qsort(array,nr,sizeof(str),cmp_nr);
	for(int i=0;i<nr;i++)
	{
		printf("%s\n",array[i].word);
	}
	
	return 0;
}
