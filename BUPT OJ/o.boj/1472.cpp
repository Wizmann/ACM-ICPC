#include <stdio.h>
#include <conio.h>


int leap(int n)
{
	if( (n%4==0&&n%100!=0) || n%400==0 ) return 1;
	else return 0;
}

int getMonth(int year,int month)
{
	int sum=0;
	switch(month)
	{
		case 12:sum+=30;
		case 11:sum+=31;
		case 10:sum+=30;
		case 9:sum+=31;
		case 8:sum+=31;
		case 7:sum+=30;
		case 6:sum+=31;
		case 5:sum+=30;
		case 4:sum+=31;
		case 3:
		{
			if(leap(year)) sum+=29;
			else sum+=28;
		};
		case 2:sum+=31;
		case 1:sum+=0;break;
	}
	return sum;
}

void print(int n)
{
	switch (n)
	{
		case 0:printf("sunday");break;
		case 1:printf("monday");break;
		case 2:printf("thusday");break;
		case 3:printf("wednesday");break;
		case 4:printf("thursday");break;
		case 5:printf("friday");break;
		case 6:printf("saturday");break;
	}
	printf("\n");
}

int main()
{
	int year,month,day;
	int sum;
	char flag;
	scanf("%d%d%d",&year,&month,&day);
	sum=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100;
	sum+=getMonth(year,month);
	sum+=day;
	print(sum%7);
	return 0;
}