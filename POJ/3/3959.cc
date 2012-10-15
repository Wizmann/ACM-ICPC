//Result:wizmann	3959	Accepted	4784K	1610MS	G++	1529B	

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define WORD 256


int space[WORD];
vector<string> mp[SIZE];
int ind;

void init()
{
    for(int i=0;i<SIZE;i++) mp[i].clear();
    ind=0;
}

inline void printspace(int x)
{
    for(int i=0;i<x;i++)
    {
        putchar(' ');
    }
}

void slove()
{
    memset(space,0,sizeof(space));
    bool flag=true;
    int ptr=0;
    while(flag)
    {
        flag=false;
        for(int i=0;i<ind;i++)
        {
            if((int)mp[i].size()>ptr)
            {
                flag=true;
                space[ptr]=max(space[ptr],(int)mp[i][ptr].length());
                //print(i<<' '<<mp[i][ptr].length()<<' '<<mp[i][ptr]);
            }
        }
        ptr++;
    }

    for(int i=0;i<ind;i++)
    {
        for(int j=0;j<(int)mp[i].size();j++)
        {
            printf("%s",mp[i][j].c_str());
            int len=mp[i][j].length();
            printspace(space[j]-len);

            putchar(' ');
        }
        putchar('\n');
    }
}




int main()
{
	char str[WORD];

	while(gets(str))
	{

	    if(*str=='\0')
	    {
	        slove();
	        init();
	    }
	    char *p=strtok(str," ");
	    while(p)
	    {
	        mp[ind].push_back(p);
	        p=strtok(NULL," ");
	    }
	    ind++;
	}
	slove();
	return 0;
}
