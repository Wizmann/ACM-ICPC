#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    map<char, int> mpa, mpb;
    string stra, strb;
    
    input(stra >> strb);
    
    for (auto c: stra) {
        mpa[c]++;
    }
    
    for (auto c: strb) {
        mpb[c]++;
    }
    // print(stra << ' ' << strb);
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        ans += min(mpa[c], mpb[c]);
    }
    print(stra.length() + strb.length() - ans * 2);
    
    return 0;
}
