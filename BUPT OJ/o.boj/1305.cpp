#include <stdio.h>

//I love SEX!!!

int& check(int sex,int &boy,int &girl)
{
	if(sex==1) return boy;
	else return girl;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int time;
	scanf("%d",&time);
	for(int i=0;i<time;i++)
	{
		int boy=0,girl=0;
		int people;
		scanf("%d",&people);
		for(int j=0;j<people;j++)
		{
			int sex;
			//I love SEX!!!
			scanf("%d",&sex);
			check(sex,boy,girl)++;
		}
		printf("%d %d\n",girl,boy);
	}
	return 0;
}