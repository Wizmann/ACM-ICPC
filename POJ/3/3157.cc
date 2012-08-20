#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define elif else if


int main()
{
	freopen("input.txt","r",stdin);
	char cmd[1024];
	while(scanf("%s",cmd)!=EOF)
	{
		//print(cmd);
		int type=0;//011 -> C++  110 -> JAVA
		for(int i=0;cmd[i];i++)
		{
			if(cmd[i]=='_') type|=1;
			elif(cmd[i]>='a'&&cmd[i]<='z') type|=2;
			elif(cmd[i]>='A'&&cmd[i]<='Z') type|=4;
		}
		if(type==7 || type==5 || type==4 || strstr(cmd,"__") ||
			cmd[strlen(cmd)-1]=='_' || !(cmd[0]>='a'&&cmd[0]<='z')) print("Error!");
		else
		{
			bool upper=false;
			for(int i=0;cmd[i];i++)
			{
				if(type==6 || type==2)
				{
					if(cmd[i]>='A' && cmd[i]<='Z')
					{
						printf("_%c",cmd[i]-'A'+'a');
					}
					else printf("%c",cmd[i]);
				}
				else if(type==2 || type==3)
				{
					if(cmd[i]=='_')
					{
						upper=true;
					}
					else
					{
						if(upper)
						{
							printf("%c",cmd[i]-'a'+'A');
							upper=false;
						}
						else printf("%c",cmd[i]);
					}
				}
			}
			print("");
		}
	}
	return 0;
}
