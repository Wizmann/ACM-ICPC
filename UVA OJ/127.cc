// Result : 127 "Accordian" Patience    Accepted    C++ 1.339   2013-11-12 15:45:50
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 1<<29;

struct Poker {
    int face;
    char suit;
    int pile;

    Poker(){}
    Poker(int iface, char isuit): \
        face(iface), suit(isuit), pile(1){}

    bool operator & (const Poker& poker) {
        return face == poker.face || suit == poker.suit;
    }
};

const size_t SIZE = 64;
const size_t BUFFER_SIZE = 1024;
Poker pokers[SIZE];
int idx = 0;
stack<Poker> stash[SIZE];
int ptr;

int toFace(char x)
{
    if (x >= '2' && x <= '9') return x - '0';
    else if (x == 'A') return 1;
    else if (x == 'T') return 10;
    else if (x == 'J') return 11;
    else if (x == 'Q') return 12;
    else if (x == 'K') return 13;
    else while(1) {print(x);}; // USE TLE TO TELL THE UNEXPECT INPUT
}

void parse(char* buffer)
{
    for (int i = 0; buffer[i]; /*PASS*/) {
        if (isalnum(buffer[i])) {
            int face = toFace(buffer[i]);
            char suit = buffer[i+1];
            pokers[idx++] = Poker(face, suit);
            i += 2;
        } else {
            i++;
        }
    }
}

void zip(int& ptr, int& pos)
{
    for (int i = pos; i < ptr; i++) {
        swap(stash[i], stash[i + 1]);
    }
    ptr--;
}

int can_move(int i) 
{
    int next = -1;
    if (i - 3 >= 0 && stash[i].top() & stash[i - 3].top()) {
        next = i - 3;
    } else if (i - 1 >= 0 && stash[i].top() & stash[i - 1].top()) {
        next = i - 1;
    }
    return next;
}
        

void do_solve(const Poker& p)
{
    stash[ptr++].push(p);
    while (1) {
        int now = -1, next = -1;
        for (int i = 0; i < ptr; i++) {
            next = can_move(i);
            now = i;
            if (-1 != next) break;
        }
        if (next == -1) break;
        Poker t = stash[now].top();
        stash[now].pop();
        stash[next].push(t);
        
        if (stash[now].empty()) {
            zip(ptr, now);
        }
    }
}
        

int main()
{
    freopen("input.txt", "r", stdin);
    char buffer[BUFFER_SIZE];
    while (1) {
        idx = 0;
        fgets(buffer, BUFFER_SIZE, stdin);
        if (*buffer == '#') break;
        parse(buffer);
        fgets(buffer, BUFFER_SIZE, stdin);
        parse(buffer);
        
        ptr = 0;
        for (int i = 0; i < (int)SIZE; i++) stash[i] = stack<Poker>();
        for (int i = 0; i < idx; i++) {
            do_solve(pokers[i]);
        }
        printf("%d pile%s remaining:", ptr, ptr > 1? "s" : "");
        for (int i = 0; i < ptr; i++) {
            printf(" %d", (int)stash[i].size());
        }
        puts("");
    }
    return 0;
}
