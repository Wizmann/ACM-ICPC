//Result:2012-10-06 15:16:11	Accepted	3753	203MS	2892K	1583 B	C++	Wizmann
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
            if(j+1<(int)mp[i].size())
            {
				printspace(space[j]-len);
				putchar(' ');
			}
        }
        printf("\n");
    }
}




int main()
{
	char str[WORD];
	int T;
	input(T);
	while(T--)
	{
		init();
		while(gets(str))
		{
			if(!*str) continue;
			if(strcmp(str,"@")==0) break;
			char *p=strtok(str," ");
			while(p)
			{
				mp[ind].push_back(p);
				p=strtok(NULL," ");
			}
			ind++;
		}
		slove();
	}
	return 0;
}

