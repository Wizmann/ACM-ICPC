#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int a,b;//两个小朋友
	long queue=0;//抓人小朋友号码和
	int n;//小朋友个数
	int i;//计数器
	int *line;

	scanf("%d",&n);//读入小朋友个数
	line=(int*)calloc(n+10,sizeof(int));
	memset(line,-1,sizeof(int)*(n+10));
    //for(i=0;i<n+10;i++) printf("%d ",line[i]);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		line[a]=b;
		queue+=b;
	}
	queue=( n*(n-1) )/2 -queue; //queue现在等于队首号码

	i=0;
	while(line[queue]!=-1&&i<=n+1)
	{
		queue=line[queue];
		//用前一个人，引出后一个人。。。相当于静态链表。。。
		//想出这个的人真TMB的聪明。。。膜拜。。。
		i++;
	}
	printf("%s\n",i==n-1?"Yes":"No");
	free(line);
	return 0;
}