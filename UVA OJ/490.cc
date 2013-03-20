//Result:490	Rotating Sentences	Accepted	C++	0.008	2013-03-19 14:13:15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 128;

char matrix[SIZE][SIZE];

int main()
{
    freopen("input.txt","r",stdin);
    memset(matrix,0,sizeof(matrix));
    char str[SIZE];
    int ptr=0;
    int n=0;
    while(gets(str) && *str!='\n' && *str)
    {
        //print(str);
        strcpy(matrix[ptr++],str);
        n = max(n,(int)strlen(str));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=ptr-1;j>=0;j--)
        {
            if(matrix[j][i]) printf("%c",matrix[j][i]);
            else printf(" ");
        }
        puts("");
    }
    return 0;
}


