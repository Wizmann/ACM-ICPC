#include <stdio.h>
#include <string.h>

#define LOCAL

int name[30];

int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	int n;
	while(scanf("%d",&n)!=-1)
	{
		memset(name,0,sizeof(name));
		for(int i=0;i<n;i++)
		{
			char temp[110];
			scanf("%s",temp);
			name[*temp-'a']++;
		}
		for(int i=0;i<26;i++)
		{
			printf("%c:%d\n",'a'+i,name[i]);
		}
	}
	return 0;
}