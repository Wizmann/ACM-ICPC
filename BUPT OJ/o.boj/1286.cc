#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[30];
	int ave,judge,paper,lead,west;
	int money;
	
	student()
	{
		money=0;
	}
	
	void setstu()
	{
		scanf("%s%d%d",name,&ave,&judge);
		
		char ch=' ';
		while(ch==' ') scanf("%c",&ch);
		if(ch=='Y') lead=1;
		else lead=0;
		ch=' ';
		
		while(ch==' ') scanf("%c",&ch);
		if(ch=='Y') west=1;
		else west=0;
		
		scanf("%d",&paper);
	}
}student;

student array[120];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) array[i].setstu();
	
	for(int i=0;i<n;i++)
	{
		//国家奖学金
		if(array[i].ave>80&&array[i].paper>=1) array[i].money+=8000;
		//五四奖学金
		if(array[i].ave>85&&array[i].judge>80) array[i].money+=4000;
		//成绩优秀奖
		if(array[i].ave>90) array[i].money+=2000;
		//西部奖学金
		if(array[i].ave>85&&array[i].west==1) array[i].money+=1000;
		//班级贡献奖
		if(array[i].judge>80&&array[i].lead==1) array[i].money+=850;
	}
	
	int max=-1;
	int pos=-1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(array[i].money>max)
		{
			max=array[i].money;
			pos=i;
		}
		sum+=array[i].money;
	}
	
	printf("%s\n%d\n%d\n",array[pos].name,array[pos].money,sum);
	return 0;
}