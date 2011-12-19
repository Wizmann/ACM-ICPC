#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct str
{
	char word[110];
	
	void setstr()
	{
		scanf("%s",word);
	}
}str;

str array[110];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	int len,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&len,&n);
		int sum=len;
		for(int i=0;i<n;i++) array[i].setstr();
		for(int i=1;i<n;i++)
		{
			int j,k;
			for(j=len,k=0;j>0;j--,k++)
			{
				if(strncmp(array[i-1].word+k,array[i].word,j)==0) break;
			}
			sum+=(len-j);
		}
		printf("%d\n",sum);
	}
	return 0;
}
	
