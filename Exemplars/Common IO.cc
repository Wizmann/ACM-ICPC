#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>

using namespace std;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X& x, T... args) { cout << x << " "; print(args...); }

void input() { /* pass */ }

template <typename...T, typename X>
void input(X& x, T&... args) { cin >> x; input(args...); }

int main()
{
    int a, b;
    string c;
    float d;
    input(a, b, c, d);
    print(a, b, c, d);
    return 0;
}
