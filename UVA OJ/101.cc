// Result:  Wizmann UVA 101 Accepted    0 KB    22 ms   C++ 4.5.3   2522 B  2013-11-18 00:28:48
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t SIZE = 32;

deque<int> dq[SIZE];
int pos[SIZE];
int n;

void show()
{
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < (int)dq[i].size(); j++) {
            printf(" %d", dq[i][j]);
        }
        puts("");
    }
}

void popup(int x, int a)
{
    int lenx = dq[x].size();
    while (lenx && dq[x][lenx - 1] != a) {
       int t = dq[x][lenx - 1];
       lenx--;
       pos[t] = t;
       dq[t].push_front(t);
       dq[x].pop_back();
    }
}

void moveup(int x, int a, int y)
{
    bool found = false;
    for (deque<int>::iterator iter = dq[x].begin();
            iter != dq[x].end();
            /*PASS*/) {
        if (*iter == a) {
            found = true;
        }
        
        if (found) {
            dq[y].push_back(*iter);
            pos[*iter] = y;
            iter = dq[x].erase(iter);
        } else {
            ++iter;
        }
    }
}

void move_onto(int a, int b)
{
    int x = pos[a];
    int y = pos[b];
    if (x == y) return;
    
    popup(x, a);
    popup(y, b);
    moveup(x, a, y);
}

void move_over(int a, int b)
{
    int x = pos[a];
    int y = pos[b];
    if (x == y) return;
    
    popup(x, a);
    moveup(x, a, y);
}

void pile_onto(int a, int b)
{
    int x = pos[a];
    int y = pos[b];
    if (x == y) return;
    
    popup(y, b);
    moveup(x, a, y);
}

void pile_over(int a, int b)
{
    int x = pos[a];
    int y = pos[b];
    if (x == y) return;
    
    moveup(x, a, y);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    string cmda, cmdb;
    input(n);
    for (int i = 0; i < n; i++) {
        dq[i].push_back(i);
        pos[i] = i;
    }

    while (1) {
        input(cmda);
        if (cmda == "quit") {
            break;
        }
        input(a >> cmdb >> b);
        
        //print(cmda << " " << a << " " << cmdb << " " << b);
        if (cmda == "move" && cmdb == "onto") {
            move_onto(a, b);
        } else if (cmda == "move" && cmdb == "over") {
            move_over(a, b);
        } else if (cmda == "pile" && cmdb == "onto") {
            pile_onto(a, b);
        } else if (cmda == "pile" && cmdb == "over") {
            pile_over(a, b);
        } else {
            // DO BAD ?
        }
        //show();
        //puts("___");
    }
    show();
    return 0;
}

