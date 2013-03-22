//Result:457    Linear Cellular Automata    Accepted    C++ 0.016   2013-03-22 14:48:40
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 44;
const int PRO = 10;

int dish[2][SIZE];
int DNA[PRO];

void show(int x,int i)
{
    int flag = dish[x][i];
    switch(flag)
    {
        case 0: putchar(' '); break;
        case 1: putchar('.'); break;
        case 2: putchar('x'); break;
        case 3: putchar('W'); break;
        default: break;
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    int T;
    input(T);
    while(T--)
    {
        memset(DNA,0,sizeof(DNA));
        memset(dish,0,sizeof(dish));
        for(int i=0;i<PRO;i++) input(DNA[i]);
        int ptr=0;
        dish[0][20]=1;
        for(int i=0;i<50;i++)
        {
            for(int j=1;j<=40;j++)
            {
                show(ptr,j);
            }
            puts("");
            int next = ptr^1;
            for(int j=1;j<=40;j++)
            {
                dish[next][j] = DNA[dish[ptr][j-1]+dish[ptr][j]+dish[ptr][j+1]];
            }
            ptr=next;
        }
        if(T) puts("");
    }
    return 0;
}





