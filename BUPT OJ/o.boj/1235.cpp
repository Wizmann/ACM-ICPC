#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dict
{
	char eng[70];
	char chn[70];
	
	dict()
	{
		memset(eng,0,sizeof(eng));
		memset(chn,0,sizeof(chn));
	}
	
	dict setdict(const char* e,const char* c)
	{
		strcpy(eng,e);
		strcpy(chn,c);
		return *this;
	}
}dict;

int cmp(const void *a,const void *b)
{
	dict *_a,*_b;
	_a=(dict*)a;
	_b=(dict*)b;
	return strcmp(_a->eng,_b->eng);
}

int main()
{
	int sex=1;
	int n;
	while(scanf("%d",&n)!=-1)
	{
		printf("Case %d:\n",sex++);
		dict *mydict=new dict[n];
		for(int i=0;i<n;i++)
		{
			char temp1[70];
			char temp2[70];
			scanf("%s%s",temp1,temp2);
			mydict[i].setdict(temp1,temp2);
		}
		
	
	
		qsort(mydict,n,sizeof(dict),cmp);
		
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			dict *find=NULL;
			char search[70];
			scanf("%s",search);
			find=(dict*)bsearch(search,mydict,n,sizeof(dict),cmp);
			if(find) printf("%s\n",find->chn);
			else printf("I can't find out this word\n");
		}
	}
	return 0;
}