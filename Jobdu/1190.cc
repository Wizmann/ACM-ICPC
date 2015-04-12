// Result: Wizmann	1190	Accepted	点击此处查看所有case的执行结果	1524KB	1088B	20MS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<string> vec;

bool cmp(const string& a, const string& b) {
    int la = a.size();
    int lb = b.size();
    
    if (la != lb) {
        return la < lb;
    }
    
    for (int i = 0; i < la; i++) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    string str;
    while (input(n)) {
        vec.clear();
    
        for (int i = 0; i < n; i++) {
            input(str);
            vec.push_back(str);
        }
        
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < n; i++) {
            print(vec[i]);
        }
    }
    return 0;
}
