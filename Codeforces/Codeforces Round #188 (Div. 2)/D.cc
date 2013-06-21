//Result:3912588     Jun 18, 2013 10:48:23 AM   Wizmann  D - Ants    GNU C++    Accepted    703 ms  1048 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 256;

int M[SIZE * 2][SIZE * 2];

void add(int y, int x)
{
    M[y][x]++;
    if(M[y][x] == 4)
    {
        M[y][x] = 0;
        add(y + 1, x);
        add(y - 1, x);
        add(y, x + 1);
        add(y, x - 1);
    }
}

int main()
{
    int n,t,x,y;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++) 
    {
        add(SIZE, SIZE);
    }

    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&x,&y);
        if(x+SIZE >= 2 * SIZE || x+SIZE < 0|| y+SIZE >= 2 * SIZE || y+SIZE < 0)
        {
            print(0);
        }
        else
        {
            print(M[y+SIZE][x+SIZE]);
        }
    }
    return 0;
}
