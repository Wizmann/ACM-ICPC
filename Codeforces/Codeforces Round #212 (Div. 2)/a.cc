// Result:Nov 15, 2013 11:48:29 AM Wizmann  A - Two Semiknights Meet    GNU C++    Accepted     15 ms   0 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t N = 8;

struct Point {
    int x,y;
    Point(){}
    Point(int ix, int iy): x(ix), y(iy){}
};

char maze[N+5][N+5];

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        for (int i = 0; i < (int)N; i++) {
            scanf("%s", maze[i]);
        }
        int p = 0;
        Point ks[2];
        for (int i = 0; i < (int)N; i++) {
            for (int j = 0; j < (int)N; j++) {
                if (maze[i][j] == 'K') {
                    ks[p++] = Point(i, j);
                }
            }
        }
        int dy = ks[0].y - ks[1].y;
        int dx = ks[0].x - ks[1].x;
        
        puts(dy % 4 == 0 && dx % 4 == 0? "YES" : "NO");
    }
    return 0;
}

