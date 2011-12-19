#include <stdio.h>
#include <string.h>

int main()
{

	int alpha[26]={52,6,18,21,71,13,26,35,46,1,6,26,17,44,61,19,1,33,32,72,26,5,13,0,15,0};

	for(int i=0;i<26;i++)
	{
		printf("%c,%d\n",'A'+i,alpha[i]);
	}
	return 0;
}