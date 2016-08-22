#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a%b, x, y);
    int t = y;
    y = x - (a / b) * y;
    x = t;
    return r;
}

int main(){
    int a, b;
    int x, y;
    input(a >> b);
    int res = exgcd(a, b, x, y); 
    
    if(res != 1) {
        puts("Not Exist");
    } else {
        int ans = (x % b + b) % b;
        print(ans);
    }
    return 0;
}
