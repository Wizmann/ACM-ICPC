#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

set<int> st;

bool is_palindrome(const string& s) {
    int n = s.size();
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void init() {
    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) {
            string s = to_string(i * j);
            if (is_palindrome(s)) {
                st.insert(i * j);
            }
        }
    }
}

int main(){
    int t;
    init();
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        auto iter = st.lower_bound(n);
        print(*(--iter));
    }
    return 0;
}
