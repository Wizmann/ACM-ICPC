#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char input;
	scanf("%c",&input);
	if(input=='a')
	{
		printf("acm.scs.bupt.cn\nacm.fzu.edu.cn\n");
	}
	else if(input=='m')
	{
		printf("mail.google.com\nmail.bupt.edu.cn\n");
	}
	else if(input=='w')
	{
		printf("www.sina.com.cn\nwww.sohu.com\nwww.baidu.com\nwww.zol.com.cn\n");
	}
	return 0;
}