#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int ILLEGAL = -1;
const int DRAW = 0;
const int FIRST = 1;
const int SECOND = 2;
const int FIRST_WIN = 100;
const int SECOND_WIN = 200;


void check_win(char board[3][3], int& a_cnt, int& b_cnt)
{
    a_cnt = b_cnt = 0;
    for (int i = 0; i < 3; i++) {
        char type = board[i][0];
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == type) {
                cnt++;
            } else {
                break;
            }
        }
        
        if (cnt == 3) {
            if (type == 'X') a_cnt++;
            else if (type == '0') b_cnt++;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        char type = board[0][i];
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == type) {
                cnt++;
            } else {
                break;
            }
        }
        
        if (cnt == 3) {
            if (type == 'X') a_cnt++;
            else if (type == '0') b_cnt++;
        }
    }
    
    do {
        char type = board[0][0];
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == type) {
                cnt++;
            } else {
                break;
            }
        }
        if (cnt == 3) {
            if (type == 'X') a_cnt++;
            else if (type == '0') b_cnt++;
        }
    } while(0);
        
    do {
        char type = board[0][2];
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (board[2 - i][i] == type) {
                cnt++;
            } else {
                break;
            }
        }
        if (cnt == 3) {
            if (type == 'X') a_cnt++;
            else if (type == '0') b_cnt++;
        }
    } while(0);
}




int judge(char board[3][3])
{
    int next = -1;
    int a_cnt = 0, b_cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') a_cnt++;
            else if (board[i][j] == '0') b_cnt++;
        }
    }
    if (a_cnt < b_cnt || a_cnt - b_cnt > 1) {
        return ILLEGAL;
    }

    if (a_cnt + b_cnt == 9) {
        // PASS
    } else if (a_cnt == b_cnt) {
        next = 1;
    } else {
        next = 2;
    }

    a_cnt = b_cnt = 0;
    check_win(board, a_cnt, b_cnt);

    if (a_cnt == 0 && b_cnt == 0) {
        //nobody wins and the board is full
        switch(next) {
            case -1:
                return DRAW;
            case 1:
                return FIRST;
            case 2:
                return SECOND;
        }
    } else if (b_cnt && a_cnt) {
        return ILLEGAL;
    } else if (b_cnt && !a_cnt) {
        if (next == 2) {
            return ILLEGAL;
        } else {
            return SECOND_WIN;
        }
    } else if (a_cnt && !b_cnt) {
        if (next == 1) {
            return ILLEGAL;
        } else {
            return FIRST_WIN;
        }
    } else {
        // NO ELSE HERE;
    }

    return next == 1? FIRST : SECOND;
}


int main()
{
    freopen("input.txt", "r", stdin);
    char board[3][3];

    for (int i = 0; i < 3; i++) {
        input(board[i]);
    }

    int ans = judge(board);
    switch(ans) {
        case -1:
            print("illegal");
            break;
        case 0:
            print("draw");
            break;
        case 1:
            print("first");
            break;
        case 2:
            print("second");
            break;
        case 100:
            print("the first player won");
            break;
        case 200:
            print("the second player won");
            break;
    }

    return 0;
}

