#include <stdio.h>

int main()
{
	char ch;
	scanf("%c",&ch);
	char temp=ch;
	temp-=5;
	while(temp<'a') temp++;
	while(temp<ch) printf("%c",temp++);
	printf("%c",temp++);
	for(int i=0;i<5&&temp<='z';i++,temp++)
	{
		printf("%c",temp);
	}
	return 0;	
}