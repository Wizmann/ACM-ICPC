#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

string solve(string s) {
    s = "0" + s;
    
    int n = s.length();

    size_t l = 0;
    
    size_t dot = s.find('.');
    if (dot == s.npos) {
        s += ".";
        dot = s.length() - 1;
    }
    
    size_t r = s.length() - 1;

    while (l < r && s[l] == '0') {
        l++;
    }
        
    int e = 0;
    while (dot - 1 > l) {
        swap(s[dot], s[dot - 1]);
        dot--;
        e++;
    }
    
    while (r > l && s[r] == '0') {
        r--;
    }
    
    if (l == r) {
        return "0";
    }
    
    while (dot == l) {
        swap(s[dot], s[dot + 1]);
        if (s[dot] == '0') {
            l++;
        }
        e--;
        dot++;
    }
    
    if (r == dot) {
        r--;
    }

    if (!e) {
        return s.substr(l, r - l + 1);
    } else {
        return s.substr(l, r - l + 1) + "E" + to_string(e);
    }
}


#define ASSERT_EQUAL(T, a, b) do { \
    printf("%d ", __LINE__); \
    assert_equal<T>(a, b); \
    puts("OK"); \
} while (0) 

template<typename T>
void assert_equal(T a, T b) {
    if (a != b) {
        print("l: " << a << ", r: " << b);
        assert(a == b);
    }
}



int main() {

#ifdef TEST
    ASSERT_EQUAL(string, solve("0"), "0");
    ASSERT_EQUAL(string, solve("00.00"), "0");
    ASSERT_EQUAL(string, solve("0.00000"), "0");
    ASSERT_EQUAL(string, solve("000.1"), "1E-1");
    ASSERT_EQUAL(string, solve("000.0000000000000001"), "1E-16");
    ASSERT_EQUAL(string, solve("123.4"), "1.234E2");
    ASSERT_EQUAL(string, solve("16"), "1.6E1");
    ASSERT_EQUAL(string, solve("100"), "1E2");
    ASSERT_EQUAL(string, solve(".100"), "1E-1");
    ASSERT_EQUAL(string, solve("0001100"), "1.1E3");
    ASSERT_EQUAL(string, solve("1.000000000000000000000000000000000000000000000000000001"), "1.000000000000000000000000000000000000000000000000000001");
    ASSERT_EQUAL(string, solve("1111111"), "1.111111E6");
#endif

    string s;
    input(s);
    print(solve(s));
    return 0;
}
